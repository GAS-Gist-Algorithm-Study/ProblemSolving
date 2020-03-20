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
  int lutInc[N];
  int lutDec[N];

  for (int i = 0; i < N; i++)
    cin >> A[i];

  lutInc[0] = 1;
  lutDec[N - 1] = 1;

  for (int i = 1; i < N; i++) {
    int maxInc = 0;

    for (int j = 0; j < i; j++) 
      if (A[j] < A[i])
        maxInc = max(maxInc, lutInc[j]);

    lutInc[i] = maxInc + 1;
  }

  for (int i = N - 2; i >= 0; i--) {
    int maxDec = 0;
    for (int j = i + 1; j < N; j++) 
      if (A[j] < A[i]) 
        maxDec = max(maxDec, lutDec[j]);

    lutDec[i] = maxDec + 1;
  }
  
  int maxBitonic = 0;
  for (int i = 0; i < N; i++)
    maxBitonic = max(maxBitonic, lutInc[i] + lutDec[i] - 1);
  
  cout << maxBitonic << endl;
  return 0;
}

