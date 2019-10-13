#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N, int scores[])
{
  int lut[N + 1][2] = {0,};
  
  lut[1][0] = scores[1];
  lut[2][0] = scores[2];
  lut[2][1] = scores[1] + scores[2];

  for (int i = 3; i <= N; i++) {
    lut[i][0] = max(lut[i - 2][1], lut[i - 2][0]) + scores[i];
    lut[i][1] = lut[i - 1][0] + scores[i];
  }

  return max(lut[N][0], lut[N][1]);
}

int main()
{
  int N;
  int scores[301];
 
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> scores[i];

  cout << solution(N, scores);
  exit(0);
}
