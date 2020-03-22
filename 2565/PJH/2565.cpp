#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define endl "\n"
#define line pair<int, int>
#define a first
#define b second

using namespace std;

int lis(int bs[], int N)
{
  int cnts[N] = { 0, };
  int maxCnt = 1;

  cnts[N - 1] = 1;
  for (int i = N - 2; i >= 0; i--) {
    cnts[i] = 1;
    for (int j = i + 1; j < N; j++) {
      if (bs[j] > bs[i]) 
        cnts[i] = max(cnts[i], 1 + cnts[j]);
    }

    maxCnt = max(maxCnt, cnts[i]);
  }

  return maxCnt;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  line lines[N];
  int crossingNums[N];
  for (int i = 0; i < N; i++)
    cin >> lines[i].a >> lines[i].b;
  
  sort(lines, lines + N);
  int bs[N];
  for (int i = 0; i < N; i++)
    bs[i] = lines[i].b;
  
  cout << N - lis(bs, N) << endl;
  return 0;
}
