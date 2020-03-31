#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

void backtracking(int step, int M, int N, vector<int>& nums)
{
  if (step == M) {
    for (int n: nums)
      cout << n << " ";
    cout << endl;
    return;
  }

  for (int i = 1; i <= N; i++) {
    nums.push_back(i);
    backtracking(step + 1, M, N, nums);
    nums.pop_back();
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<int> nums;
  backtracking(0, M, N, nums);
  return 0;
}
