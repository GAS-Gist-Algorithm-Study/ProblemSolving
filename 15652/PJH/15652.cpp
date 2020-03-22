#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

void backtrack(int step, int M, int N, vector<int>& seq)
{
  if (step == M) {
    for (int n: seq)
      cout << n << " ";
    cout << endl;

    return;
  }

  int last = seq.size() ? seq.back() : 1;
  for (int i = last; i <= N; i++) {
    seq.push_back(i);
    backtrack(step + 1, M, N, seq);
    seq.pop_back();
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> seq;
  backtrack(0, M, N, seq);

  return 0;
}

