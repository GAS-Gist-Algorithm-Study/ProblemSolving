#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define stuff pair<int, int>
#define weight first
#define value second

using namespace std;

int dp(stuff stuffs[], int lut[][100], int N, int K, int i)
{
  if (K <= 0) 
    return 0;
  if (i >= N)
    return 0;
  if (lut[K][i] != -1)
    return lut[K][i];

  int maxValue = 0;
  
  if (K >= stuffs[i].weight)
    maxValue = max(maxValue, stuffs[i].value + dp(stuffs, lut, N, K - stuffs[i].weight, i + 1));

  maxValue = max(maxValue, dp(stuffs, lut, N, K, i + 1));

  return lut[K][i] = maxValue;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;

  stuff stuffs[N];
  for (int i = 0; i < N; i++) 
    cin >> stuffs[i].weight >> stuffs[i].value;
  
  int lut[K + 1][100];
  for (int i = 0; i <= K; i++) 
    for (int j = 0; j < 100; j++)
      lut[i][j] = -1;

  for (int i = 0; i < 100; i++)
    lut[0][i] = 0;


  cout << dp(stuffs, lut, N, K, 0) << endl;
  return 0;
}

