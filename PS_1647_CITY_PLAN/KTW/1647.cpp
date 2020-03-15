#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int src, des, cost;
    Edge(int a=0, int b=0, int c=0): src(a), des(b), cost(c) {}
    bool operator<(const Edge &e) const{
        return cost < e.cost;
    }
};

int find(int cities[], int city){
    if(cities[city]==city) return city;
    return find(cities, cities[city]);
}

bool Union(int cities[],int &a, int &b){
    int A = find(cities, a);
    int B = find(cities, b);
    if(A==B) return false;
    if(A>B) cities[A] = B;
    else cities[B]=A;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<Edge> Edges;
    Edges.reserve(M);
    for(int m = 0; m < M; m++){
        int a,b,c;
        cin >> a >> b >> c;
        Edges.emplace_back(Edge(a,b,c));
    }
    sort(Edges.begin(),Edges.end());
   
    int* cities = (int*)malloc((N+1)*sizeof(int));
    for(int i = 1; i <= N; i++) cities[i]=i;
   
    int ans = 0;
    int max;
    int recur = 1;
    for(auto i : Edges)
        if(Union(cities, i.src, i.des)) {
            ans += i.cost;
            max = i.cost;
            recur++;
            if(recur == N) break;
        }
    cout << ans-max;
}
