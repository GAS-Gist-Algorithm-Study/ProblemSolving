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

  int triangle[n][n];
  int lut[n][n];

  for (int i = 0; i < n; i++) 
    for (int j = 0; j <= i; j++) 
      cin >> triangle[i][j];

  for (int i = 0; i < n; i++) 
    lut[n - 1][i] = triangle[n - 1][i];

  for (int i = n - 2; i >= 0; i--) 
    for (int j = 0; j <= i; j++) 
      lut[i][j] = triangle[i][j] + max( lut[i + 1][j], lut[i + 1][j + 1]);

  cout << lut[0][0] << endl;
  return 0;
}

