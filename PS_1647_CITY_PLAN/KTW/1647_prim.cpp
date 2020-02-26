#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool visited[100001];

struct Edge{
    int des;
    int cost;

    Edge(int d, int c) : des(d), cost(c) {}
    
    bool operator<(const Edge &e)const{
        return cost > e.cost;
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<Edge> edges[N+1];
    for (int m=0 ; m<M ; m++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].emplace_back(Edge(b,c));
        edges[b].emplace_back(Edge(a,c));
    }
    priority_queue<Edge> pq;
    int ans=0;
    int max=0;
    int cur=1;

    visited[1] = true;
    for(auto i: edges[1]) pq.emplace(i);
    while(cur<N && !pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if(visited[e.des]){
            continue;
        }
        visited[e.des] = true;
        ans += e.cost;
        if(max < e.cost)
            max = e.cost;
        cur++;
        for(auto j: edges[e.des]) pq.emplace(j);
    }
    cout << ans - max;

}