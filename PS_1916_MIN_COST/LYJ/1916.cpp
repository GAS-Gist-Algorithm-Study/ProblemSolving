#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define INF 987654321

using namespace std;
typedef pair<int, int> pii;

struct Edge{
    int start;
    int end;
    int cost;
    bool operator >(const Edge &A) const{
        return cost > A.cost;
    }
};

int minCost(int startCity, int endCity, vector<pii> (&adjList)[1001]){
    int costs[1001];
    for (int i = 0; i < 1001; i++)
        costs[i] = 0x7fffffff;
    costs[startCity] = 0;
    
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    Edge temp;
    for(int i=0;i<adjList[startCity].size();i++){
        temp.start = startCity;
        temp.end = adjList[startCity][i].second;
        temp.cost = adjList[startCity][i].first;
        pq.push(temp);
    }

    Edge cur;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        if( costs[cur.end] > costs[cur.start] + cur.cost ){
            costs[cur.end] = costs[cur.start] + cur.cost;
            for(int i=0;i<adjList[cur.end].size();i++){
                temp.start = cur.end;
                temp.end = adjList[cur.end][i].second;
                temp.cost = adjList[cur.end][i].first;
                pq.push(temp);
            }
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
        adjList[temp1].emplace_back(make_pair(temp3, temp2));
    }

    int startCity, endCity;
    cin >> startCity >> endCity;
    
    cout << minCost(startCity, endCity, adjList) << endl;
}