#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int prices[3][N];
  int lut[3][N];

  for (int i = 0; i < N; i++) 
    cin >> prices[0][i]
        >> prices[1][i]
        >> prices[2][i];

  for (int i = 0; i < 3; i++) 
    lut[i][0] = prices[i][0];

  for (int i = 1; i < N; i++) {
    lut[0][i] = prices[0][i] + min(
        lut[1][i - 1],
        lut[2][i - 1] 
      );

    lut[1][i] = prices[1][i] + min (
        lut[0][i - 1],
        lut[2][i - 1]
      );
   
    lut[2][i] = prices[2][i] + min (
        lut[0][i - 1],
        lut[1][i - 1]
      );
  }

  int minCost = 987654321;
  for (int i = 0; i < 3; i++) 
    minCost = min(minCost, lut[i][N -1]);

  cout << minCost << '\n';
  return 0;
}

