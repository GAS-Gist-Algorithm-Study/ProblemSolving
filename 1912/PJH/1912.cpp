#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int nums[n + 1];
  int accSums[n + 1];
  for (int i = 1; i <= n; i++)
    cin >> nums[i];

  accSums[0] = 0;
  for (int i = 1; i <= n; i++)
    accSums[i] = accSums[i - 1] + nums[i];

  int minSum = 0;
  int maxSum = accSums[1];

  for (int i = 1; i <= n; i++) {
    minSum = min(minSum, accSums[i - 1]);
    maxSum = max(maxSum, accSums[i] - minSum);
    maxSum = max(maxSum, nums[i]);
  }

  cout << maxSum << endl;
  return 0;
}

