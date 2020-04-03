#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int visited[100001];
  for (int i = 0; i <= 100000; i++)
    visited[i] = -1;
  int N, K;
  cin >> N >> K;

  queue<pair<int, int>> q;
  q.emplace(N, 0);
  visited[N] = 0;

  int cnt = 0;
  while (!q.empty()) {
    pair<int, int> now = q.front();
    int n = now.first;
    int step = now.second;
    q.pop();

    cnt = step;
    if (n == K) 
      break; 

    if (n - 1 >= 0)
      if (visited[n - 1] == -1) {
        q.emplace(n - 1, step + 1);
        visited[n - 1] = step + 1;
      }
    
    if (n + 1 <= 100000)
      if (visited[n + 1] == -1) {
        q.emplace(n + 1, step + 1);
        visited[n + 1] = step + 1;
      }
    
    if (n * 2 <= 100000)
      if (visited[n * 2] == -1) {
        q.emplace(n * 2, step + 1);
        visited[n * 2] = step + 1;
      }
  }

  cout << cnt;
  return 0;
}
