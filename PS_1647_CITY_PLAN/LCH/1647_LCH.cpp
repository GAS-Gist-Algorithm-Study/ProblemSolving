#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int x, y, w;
}edge;

int root[100001];
vector<edge> v;

int findRoot(int n){
    while(root[n] != 0) n = root[n];
    return n;
}

int makeUnion(int n, int m){
    int root_n = findRoot(n), root_m = findRoot(m);
    if(root_n == root_m) return 0;
    if(root_n > root_m)
        root[root_n] = root_m;
    else root[root_m] = root_n;
    return 1;
}

bool compare(const edge &a, const edge &b){
    return a.w < b.w;
}

int findMST(int n){
    int ret = 0, count = 0, max = -1, size = v.size();
    for(int i=0; i<size; i++){
        if(count == n-1) break;
        
        if(makeUnion(v[i].x, v[i].y)){
            ret += v[i].w;
            if(max < v[i].w) max = v[i].w;
            count++;
        }
    }
    return ret - max;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        edge temp;
        scanf("%d %d %d", &temp.x, &temp.y, &temp.w);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end(), compare);
    
    printf("%d", findMST(n));
}
