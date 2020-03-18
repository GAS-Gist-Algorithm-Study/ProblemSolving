#include <iostream>

using namespace std;

int main()
{
  int lut[1000001] = { 0, 1, 2,  };

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  for (int i = 3; i <= N; i++) 
    lut[i] = (lut[i - 1] + lut[i - 2]) % 15746;
  

  cout << lut[N] << '\n';
  return 0;
}
