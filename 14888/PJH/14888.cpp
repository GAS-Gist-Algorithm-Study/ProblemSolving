#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

void  backtrack(int step, int N, int now, int nums[], int opNums[], int& minResult, int& maxResult)
{
  if (step == N) {
    minResult = min(minResult, now);
    maxResult = max(maxResult, now);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if(opNums[i]) {
      opNums[i]--;
      int newNow;
      switch (i) {
        case 0:
          newNow = now + nums[step];
          break;
        case 1:
          newNow = now - nums[step];
          break;
        case 2:
          newNow = now * nums[step];
          break;
        case 3:
          newNow = now / nums[step];
          break;
      }
      backtrack(step + 1, N, newNow, nums, opNums, minResult, maxResult);
      opNums[i]++;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int nums[N];
  for (int i = 0; i < N; i++)
    cin >> nums[i];

  int opNums[4];
  for (int i = 0; i < 4; i++)
    cin >> opNums[i];

  int minResult = 1000000000 + 1;
  int maxResult = -1000000000 - 1;
  backtrack(1, N, nums[0], nums, opNums, minResult, maxResult);

  cout << maxResult << endl
       << minResult << endl;
  return 0;
}

