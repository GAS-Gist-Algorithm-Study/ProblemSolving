#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int lut[10][N + 1];

  for (int i = 0; i < 10; i++) 
    lut[i][0] = 0;
  
  for (int i = 0; i < 10; i++) 
    lut[i][1] = (i != 0);

  for (int i = 2; i <= N; i++) {
    for (int n = 0; n < 10; n++) {
      lut[n][i] = 
        (((n - 1) >= 0 ? lut[n - 1][i - 1] : 0) 
        + ((n + 1) < 10 ? lut[n + 1][i - 1] : 0)) 
          % 1000000000;
    }
  }

  int ans = 0;
  for (int n = 0; n < 10; n++) { 
    ans += lut[n][N];
    ans %= 1000000000;
  }

  cout << ans << endl;
  return 0;
}
