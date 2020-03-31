#include <cstdio>

int main(void)
{
  long long lut[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

  for (int i = 11; i <= 100; i++) 
    lut[i] = lut[i - 1] + lut[i - 5];

  int T;
  int n;

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &n);
    printf("%lld\n", lut[n]);
  }

  return 0;
}
