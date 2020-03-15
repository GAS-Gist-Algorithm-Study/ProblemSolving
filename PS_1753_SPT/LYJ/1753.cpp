#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

struct Edge{
    int node;
    int weight;
    Edge() {}
    Edge(int node , int weight) : node(node), weight(weight) {}
    bool operator > (const Edge &A) const{
        return weight > A.weight;
    }
};

void minCosts(vector<Edge> adjList[], int V, int startNode){
    vector<int> costs(V+1, INT_MAX);
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

    pq.emplace(Edge(startNode, 0));
    costs[startNode] = 0;

    while(!pq.empty()){
        int curNode = pq.top().node;
        int curWeight = pq.top().weight;
        pq.pop();

        if(curWeight > costs[curNode]) continue;

        for(auto i : adjList[curNode]){
            if(costs[i.node] > costs[curNode] + i.weight){
                costs[i.node] = costs[curNode] + i.weight;
                pq.emplace(Edge(i.node, costs[i.node]));
            }
        }
    }

    for(int i=1;i<=V;i++){
        if(costs[i] == INT_MAX) cout << "INF" << '\n';
        else cout << costs[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, startNode;
    cin >> V >> E >> startNode;

    vector<Edge> adjList[V+1];
    
    int nodeTo, nodeFrom, weight;
    for(int i=0;i<E;i++){
        cin >> nodeFrom >> nodeTo >> weight;
        adjList[nodeFrom].emplace_back(Edge(nodeTo, weight));
    }
    
    minCosts(adjList, V, startNode);
    return 0;
}