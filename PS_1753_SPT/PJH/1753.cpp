#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

#define edge pair<int, int>
#define minCost pair<int, int>
#define minHeap priority_queue<minCost, vector<minCost>, greater<minCost> >
#define cost first
#define to second

using namespace std;

bool relax(int minCostTo[], edge& e, int node)
{
  if (minCostTo[e.to] <= minCostTo[node] + e.cost) 
    return false;

  minCostTo[e.to] =  minCostTo[node] + e.cost;
  return true;
}

void findSPT(minHeap& pq, vector<vector<edge>>& edges, int minCostTo[])
{
  while (!pq.empty()) {
    minCost curNode = pq.top();
    pq.pop();
    
    if (curNode.cost > minCostTo[curNode.to])
      continue;

    for (edge& e: edges[curNode.to]) 
      if (relax(minCostTo, e, curNode.to)) 
        pq.emplace(minCostTo[e.to], e.to);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;
  
  int K;
  cin >> K;

  vector<vector<edge>> edges(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(w, v);
  }


  int minCostTo[N + 1] = {0, };
  for (int i = 1; i <= N; i++)
    minCostTo[i] = 0x7fffffff;
  minCostTo[K] = 0;

  minHeap pq;
  pq.emplace(0, K);

  findSPT(pq, edges, minCostTo);

  for (int i = 1; i <= N; i++)
    if (minCostTo[i] == 0x7fffffff)
      cout << "INF" << endl;
    else
      cout << minCostTo[i] << endl;
  return 0;
}
