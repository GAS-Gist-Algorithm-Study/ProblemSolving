#include <iostream>
#include <queue>

using namespace std;

int troll = [10]={0,};
bool adj[1001][1001];
bool visited[1001];
int N, M, V;


void visitedInit()
{
  for (int i = 0; i < 1001; i++)
    visited[i] = false;
}

void DFS(int start)
{
  cout << start << " ";
  visited[start] = true;
  for (int i = 1; i <= N; i++) {
    if (adj[start][i]) {
      if (visited[i])
        continue;
      DFS(i);
    }
  }
}

void BFS()
{
  queue<int> q;
  q.push(V);
  visited[V] = true;

  while (!q.empty()) {
    cout << q.front() << " ";
    for (int i = 1; i <= N; i++) {
      if (adj[q.front()][i]) {
        if (visited[i])
          continue;
        q.push(i);
        visited[i] = true;
      }
    }
    q.pop();
  }

}

int main()
{
  cin >> N >> M >> V;
 
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    adj[u][v] = adj[v][u] = true;
  }

  DFS(V);
  visitedInit();
  endl(cout);
  BFS();
  return 0;
}

