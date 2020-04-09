#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

int map[1000 * 1000];
bool visited[2][1000 * 1000];
int dis[4] = { 0, 0, 1, -1 };
int djs[4] = { 1, -1, 0, 0 };

int serialize(int i, int j) 
{ return i * 1000 + j; }

bool isValid(int i, int j, int N, int M)
{ return (i >= 0 && i < N && j >= 0 && j < M); }

int bfs(int N, int M)
{
  queue<pair<int, pair<int, int>>> q;
  q.emplace(serialize(0, 0), make_pair(1, 1));
  visited[1][0] = true;

  while (!q.empty()) {
    pair<int, pair<int, int>> now = q.front();
    q.pop();

    int i = now.first / 1000;
    int j = now.first % 1000;
    int step = now.second.first;
    int canBreak = now.second.second;

    if (i == N - 1 && j == M - 1)
      return step;

    for (int k = 0; k < 4; k++) {
      int newi = i + dis[k];
      int newj = j + djs[k];

      if (!isValid(newi, newj, N, M))
        continue;

      if (visited[canBreak][serialize(newi, newj)])
        continue;
      
      switch (map[serialize(newi, newj)]) {
      case 0:
        q.emplace(serialize(newi, newj), make_pair(step + 1, canBreak));       
        visited[canBreak][serialize(newi, newj)] = true;
        break;
      case 1:
        if (canBreak) {
          q.emplace(serialize(newi, newj), make_pair(step + 1, 0));       
          visited[canBreak][serialize(newi, newj)] = true;
        }
        break;
      }
    }
  }
  
  return -1;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      cin >> c; 
      map[serialize(i, j)] = c - '0';
    }
  }

  cout << bfs(N, M) << endl;
  return 0;
}
