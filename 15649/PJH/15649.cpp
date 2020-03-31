#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

void printSeq(const vector<int>& seq)
{
  for (int n: seq)
    cout << n << " ";
  cout << endl;
}

void backtrack(vector<int>& seq, bool used[], int N, int M)
{
  if (M == 0) {
    printSeq(seq);
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (used[i]) 
      continue;

    seq.push_back(i);
    used[i] = true;
    backtrack(seq, used, N, M - 1);
    seq.pop_back();
    used[i] = false;
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  bool used[N + 1] = { 0, };

  vector<int> seq;
  backtrack(seq, used, N, M);

  return 0;
}

