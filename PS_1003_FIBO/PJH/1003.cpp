#include <iostream>

using namespace std;

int main()
{
  int lut_zero[41] = { 1, 0, 1, 1, 2 };
  int lut_one[41] = { 0, 1, 1, 2, 3 };

  for (int i = 4; i <= 40; i++) {
    lut_zero[i] = lut_zero[i - 1] + lut_zero[i - 2];
    lut_one[i] = lut_one[i - 1] + lut_one[i - 2];
  }

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    cout << lut_zero[n] << " " << lut_one[n] << '\n';
  }
  
  return 0;
}
