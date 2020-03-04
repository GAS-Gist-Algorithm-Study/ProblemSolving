#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define max_cost 1000000

using namespace std;

typedef pair<int,int> pii;

class Edge{
    public:
    int u, v, cost;

    void set_Edge(int sp, int ep, int w){
        u = sp;
        v = ep;
        cost = w;
    }
};

class Comp{
    public:
    bool operator()(Edge e1, Edge e2){
        return e1.cost > e2.cost;
    }
};

void Dijkstra(vector<Edge> Edges[], int* distance, int sp){
    priority_queue<Edge, vector<Edge>, Comp> G;
    Edge front;
    front.set_Edge(sp,sp,0);
    cout << front.u << " " << front.v << " "<< front.cost<< endl;
    G.push(front);
    distance[sp] = 0;

    while(!G.empty()){
        int u = G.top().u;
        G.pop();
        for(int i = 0; i<Edges[u].size();i++){
            int v = Edges[u][i].v;
            if(distance[v]> distance[u] + Edges[u][i].cost){
                distance[v] = distance[u] + Edges[u][i].cost;
                G.push(Edges[u][i]);
            }
        }
    }
}

void printDistance(int* distance, int V){
    for(int i = 1; i<V+1; i++){
        int dist = distance[i];

        if(dist == max_cost)
            cout << "INF" << endl; 
        else
            cout << distance[i] << endl;
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    Edge edge;
    vector<Edge> Edges[20001];
    int distance[20001];

    int V, E, K, u, v, w;
    cin >> V >> E;
    cin >> K;

    for(int i = 1; i< V+1; i++){
        distance[i] = max_cost; 
    }

    for(int i = 0; i<E; i++){
        cin >> u >> v >> w;
        edge.set_Edge(u,v,w);  
        Edges[u].push_back(edge);
    }

    Dijkstra(Edges, distance, K);
    printDistance(distance, V);
}