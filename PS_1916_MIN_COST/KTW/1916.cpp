#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#define cost first
#define des second
using namespace std;

typedef pair<int,int> edge;
typedef pair<int,int> node;

int main(){
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<edge> Edges[N+1];
    for (int m = 0; m < M; m++){
        int src,des,cost;
        cin >> src >> des >> cost;
        Edges[src].emplace_back(cost,des);
    }

    int start,end;
    cin >> start >> end;
   
    int* cities = (int*) malloc (sizeof(int)*(N+1));
    bool* visited = (bool*) malloc (sizeof(bool)*(N+1));
    for (int i = 1; i <= N; i++){
       if (i==start) {
           cities[i] = 0;
           visited[i] = true;
       }
       else cities[i] = INT_MAX;
       visited[i] = false;
    }
    
    priority_queue<node,vector<node>,greater<node> > pq;
    node n_start;
    n_start.cost = 0;
    n_start.des = start;
    pq.emplace(n_start);
    while(pq.size()>0){
        node tmp = pq.top();
        if( tmp.des == end ){
            cout << tmp.cost;
            break;
        }
        pq.pop();
        
        if( visited[tmp.des] ) continue;
        
        for( auto i:Edges[tmp.des] ){
            if( visited[i.des] ) continue;
            if( cities[i.des] > tmp.cost + i.cost ){
                cities[i.des] = tmp.cost + i.cost;
                pq.emplace(cities[i.des],i.des);
            }
        }
        visited[tmp.des] = true;
    }
    return 0;
}
