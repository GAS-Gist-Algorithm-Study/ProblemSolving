#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<int> makeTable(const string& s)
{
  int m = s.size();
  vector<int> table(m, 0);

  int j = 0;
  table[0] = j;
  for (int i = 1; i < m; i++) {
    while (j > 0 && s[i] != s[j])
      j = table[j - 1];

    if (s[i] == s[j])
      table[i] = ++j;
  }

  return table;
}

int solve(const string& s)
{
  int m = s.size();
  vector<int>&& table = makeTable(s);

  int aSize = m - table[m - 1];

  if (m % aSize == 0)
    return m / aSize;

  return 1;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    string s;
    cin >> s;

    if (s == ".")
      break;

    cout << solve(s) << endl;
  }

  return 0;
}
