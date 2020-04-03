#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"
#define yxs pair<yx, int>
#define yx pair<int, int>
#define y first
#define x second

using namespace std;

int BFS(int ** map, int N, int M)
{

  queue<yxs> q;
  q.emplace(make_pair(1, 1), 1);


  while (!q.empty()) {
    yxs now = q.front();
    q.pop();

    yx& loc = now.first;
    if (loc.y > N || loc.y <= 0 || loc.x > M || loc.x <= 0)
      continue;

    if (map[loc.y][loc.x] == 0)
      continue;

    if (loc.y == N && loc.x == M)
      return now.second;

    map[loc.y][loc.x] = 0;

    q.emplace(make_pair(loc.y + 1, loc.x), now.second + 1);
    q.emplace(make_pair(loc.y - 1, loc.x), now.second + 1);
    q.emplace(make_pair(loc.y, loc.x + 1), now.second + 1);
    q.emplace(make_pair(loc.y, loc.x - 1), now.second + 1);
  }

  return -1;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  int ** map = new int * [N + 1];
  for (int i = 1; i <= N; i++)
    map[i] = new int[M + 1];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      char c;
      cin >> c;
      map[i][j] = c - '0';
    }
  }
  
  cout << BFS(map, N, M) << endl;

  for (int i = 1; i <= N; i++)
    delete map[i];
  delete map;

  return 0;
}

