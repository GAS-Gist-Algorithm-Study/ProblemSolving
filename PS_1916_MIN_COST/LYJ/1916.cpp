#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
typedef pair<int, int> pii;

struct Edge{
    int start;
    int end;
    int cost;
    Edge() {}
    Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {}
    bool operator >(const Edge &A) const{
        return cost > A.cost;
    }
};

int minCost(int startCity, int endCity, vector<pii> adjList[]){
    int costs[1001];
    for (int i = 0; i < 1001; i++)
        costs[i] = INT_MAX;
    costs[startCity] = 0;
    
    queue<Edge> q;
    Edge temp;
    for(auto i : adjList[startCity])
        q.emplace(Edge(startCity, i.second, i.first));
    
    Edge cur;
    int vecSize;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        vecSize = adjList[cur.end].size();
        if( costs[cur.end] > costs[cur.start] + cur.cost ){
            costs[cur.end] = costs[cur.start] + cur.cost;
            for(auto i : adjList[cur.end])
                q.emplace(Edge(cur.end, i.second, i.first));
        }
    }
    return costs[endCity];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int numCity, numBus;
    cin >> numCity >> numBus;

    vector<pii> adjList[1001];
    int temp1, temp2, temp3;
    for(int i=0;i<numBus;i++){
        cin >> temp1 >> temp2 >> temp3;
        adjList[temp1].emplace_back(temp3, temp2);
    }

    int startCity, endCity;
    cin >> startCity >> endCity;
    
    cout << minCost(startCity, endCity, adjList) << endl;
}