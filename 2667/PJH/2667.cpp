#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#define endl "\n"

using namespace std;

int dys[4] = { 0, 0, -1, 1 };
int dxs[4] = { -1, 1, 0, 0 };

int dfs(vector<string>& map, int N, int i, int j)
{
  int cnt = 0;
  stack<pair<int, int>> st;
  st.emplace(i, j);

  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();

    if (map[y][x] == '0')
      continue;

    cnt++;
    map[y][x] = '0';
    
    for (int k = 0; k < 4; k++) {
      int newy = dys[k] + y;
      int newx = dxs[k] + x;

      if (newy < 0 || newy >= N || newx < 0 || newx >= N)
        continue;
    
      st.emplace(newy, newx);
    }
  }

  return cnt;
}

vector<int> solve(vector<string>& map, int N)
{
  vector<int> ans;
  int cnt = 1;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == '1') 
        ans.push_back(dfs(map, N, i, j));

  sort(ans.begin(), ans.end());
  return move(ans);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<string> map(N);
  for (int i = 0; i < N; i++)
    cin >> map[i];

  vector<int>&& ans = solve(map, N);
  cout << ans.size() << endl;
  for (int n: ans)
    cout << n << endl;

  return 0;
}

