#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define max_cost 1000000

using namespace std;

typedef pair<int,int> pii;

class Edge{
    public:
    int v, cost;
    Edge() {}
    Edge(int ep, int w){
        v = ep;
        cost = w;
    }

    void set_Edge(int ep, int w){
        //u = sp;
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
    // cout << front.u << " " << front.v << " "<< front.cost<< endl;
    Edge edge;
    edge.set_Edge(sp,0);

    G.push(edge);
    distance[sp] = 0;

    while(!G.empty()){
        edge = G.top();
        int u = edge.v;
        G.pop();
        for(int i = 0; i<Edges[u].size();i++){
            int v = Edges[u][i].v;
            if(distance[v]> distance[u] + Edges[u][i].cost){
                distance[v] = distance[u] + Edges[u][i].cost;
                G.emplace(Edges[u][i].v, distance[v]);
            }
        }
    }
}

void printDistance(int* distance, int V){
    for(int i = 1; i<V+1; i++){
        int dist = distance[i];

        if(dist == max_cost)
            cout << "INF\n"; 
        else
            cout << distance[i] << "\n";
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
        edge.set_Edge(v,w);  
        Edges[u].push_back(edge);
    }

    Dijkstra(Edges, distance, K);
    printDistance(distance, V);
}