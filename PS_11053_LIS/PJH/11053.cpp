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

  int A[N];
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int lut[N];
  lut[N - 1] = 1;

  for (int i = N - 2; i >= 0; i--) {
    int maxCnt = 0;
    for (int j = i + 1; j < N; j++) 
      if (A[j] > A[i])
        maxCnt = max(maxCnt, lut[j]);
    
    lut[i] = maxCnt + 1;
  }
  
  cout << *max_element(lut, lut + N) << endl;
  return 0;
}
