#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

bool put(bool map[][15], int y, int x, int N)
{
  for (int i = 0; i < y; i++) 
    if (map[i][x])
      return false;

  for (int i = 1; i <= y; i++) 
    if ((x - i >= 0) && map[y - i][x - i]) 
      return false;
  
  for (int i = 1; i <= y; i++) 
    if ((x + i < N) && map[y - i][x + i]) 
      return false;

  return true;
}

int backtrack(bool map[][15], int step, int N)
{
  if (step == N)
    return 1;

  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (put(map, step, i, N)) {
      map[step][i] = true;
      cnt += backtrack(map, step + 1, N);
      map[step][i] = false;
    }
  }

  return cnt;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  bool map[15][15] = { 0, };
  cout << backtrack(map, 0, N);

  return 0;
}
