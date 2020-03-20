#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int getMaxAmount(int amounts[], int lut[], int i, int n)
{
  if (lut[i] != -1)
    return lut[i];

  int maxAmount = 0;

  if (i + 3 <= n)
    maxAmount = max(
      amounts[i] + amounts[i + 1] + getMaxAmount(amounts, lut, i + 3, n),
      maxAmount
    );

  if (i + 2 <= n)
    maxAmount = max(
      amounts[i] + getMaxAmount(amounts, lut, i + 2, n),
      maxAmount
    );

  maxAmount = max(
    getMaxAmount(amounts, lut, i + 1, n),
    maxAmount
  );

  return lut[i] = maxAmount;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int amounts[n];
  for (int i = 0; i < n; i++) 
    cin >> amounts[i];

  int lut[n + 1];
  for (int i = 0; i < n; i++)
    lut[i] = -1;
  lut[n] = 0;
  lut[n - 1] = amounts[n - 1];
  lut[n - 2] = amounts[n - 2] + amounts[n - 1];

  cout << getMaxAmount(amounts, lut, 0, n) << endl;
  return 0;
}
