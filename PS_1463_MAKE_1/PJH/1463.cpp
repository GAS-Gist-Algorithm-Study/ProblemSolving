#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(const int& a, const int& b, const int& c)
{
  return min(
    min(a, b),
    min(b, c)
  );
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int lut[N + 1] = { 0, 0, 1, 1 };

  for (int i = 4; i <= N; i++) {
    lut[i] = 1 + min(
      lut[i - 1],
      (i % 2 == 0) ? lut[i / 2] : 987654321,
      (i % 3 == 0) ? lut[i / 3] : 987654321
    );
  }

  cout << lut[N] << '\n';
  return 0;
}
