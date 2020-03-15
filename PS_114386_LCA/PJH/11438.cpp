#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct node 
{
  int depth = 0;
  int kth_parent[18] = {0, };
};

void fill_table(vector<node>& nodes, int child, int parent)
{
  nodes[child].kth_parent[0] = parent;
  int i = 1;
  while (true) {
    int middle_ancestor = nodes[child].kth_parent[i - 1];

    if (nodes[middle_ancestor].kth_parent[i - 1] == 0)
      break;

    nodes[child].kth_parent[i] = 
      nodes[middle_ancestor].kth_parent[i - 1];
    i++;
  }
}

void BFS(const vector<int> neighbors[], vector<node>& nodes) 
{
  queue<int> q;
  
  int depth = 1;
  nodes[1].depth = depth;
  q.push(1);

  while(!q.empty()) {
    int parent = q.front();
    q.pop();
    
    for (int child: neighbors[parent]) {
      if (nodes[child].depth != 0)
        continue;

      nodes[child].depth = nodes[parent].depth + 1;
      q.push(child);

      fill_table(nodes, child, parent);
    }
  }
}

int lift_up(const vector<node>& nodes, int depth, int v)
{
  stack<int> ks;
  int gap = nodes[v].depth - depth;

  for (int i = 0; (1 << i) <= gap; i++) 
    if ((1 << i) & gap)
      ks.push(i);

  while (!ks.empty()) {
    int k = ks.top();
    ks.pop();
    v = nodes[v].kth_parent[k];
  }

  return v;
}

int LCA(const vector<node>& nodes, int u, int v)
{
  if (nodes[u].depth > nodes[v].depth)
    return LCA(nodes, v, u);

  v = lift_up(nodes, nodes[u].depth, v);

  while (true) {
    if (u == v) 
      return u;

    for (int k = 0; k < 18; k++) {
      if (nodes[u].kth_parent[k] == 0) {
        u = nodes[u].kth_parent[k - 1];
        v = nodes[v].kth_parent[k - 1];

        break;
      }
      
      if (nodes[u].kth_parent[k] == nodes[v].kth_parent[k]) {
        u = nodes[u].kth_parent[k ? k - 1 : k];
        v = nodes[v].kth_parent[k ? k - 1 : k];

        break;
      } 
    }
  }

  return nodes[u].kth_parent[0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int> neighbors[N + 1];
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    neighbors[u].push_back(v);
    neighbors[v].push_back(u);
  }
  
  vector<node> nodes(N + 1); 
  for (int i = 1; i <= N; i++)
    nodes[i].depth = 0;

  BFS(neighbors, nodes);

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    cout << LCA(nodes, u, v) << "\n";
  }

  return 0;
}
