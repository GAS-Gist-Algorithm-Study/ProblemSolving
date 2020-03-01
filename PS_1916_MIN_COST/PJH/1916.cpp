#include <iostream>
#include <vector>
#include <queue>

#define edge pair<int, int>
#define minCost pair<int, int>
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

void findSPT(priority_queue<minCost>& pq, vector<vector<edge>>& edges, int minCostTo[])
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
  
  vector<vector<edge>> edges(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(w, v);
  }

  int src, dst;
  cin >> src >> dst;

  int minCostTo[N + 1] = {0, };
  for (int i = 1; i <= N; i++)
    minCostTo[i] = 0x7fffffff;
  minCostTo[src] = 0;

  priority_queue<minCost> pq;
  pq.emplace(0, src);

  findSPT(pq, edges, minCostTo);

  cout << minCostTo[dst] << endl;
  return 0;
}
