#include <iostream>
#define WALL true

using namespace std;

long long lut[4][32][32];
bool map[32][32];
int N;

bool isValid(int state, int y, int x) {
  switch (state) {
  case 1:
    if (x + 1 >= N)
      return false;

    for (int i = 0; i < 2; i++) 
      if (map[y][x + i] == WALL)
        return false;
    
    break;

  case 2:
    if (y + 1 >= N)
      return false;

    for (int i = 0; i < 2; i++) 
      if (map[y + i][x] == WALL)
        return false;
    
    break;

  case 3:
    if (x + 1 >= N || y + 1 >= N) 
      return false;

    for (int i = 0; i < 2; i++) 
      for (int j = 0; j < 2; j++) 
        if (map[y + i][x + j] == WALL)
          return false;
    
    break;
  }

  return true;
}

long long dp(int state, int y, int x) {
  if (lut[state][y][x] != -1)
    return lut[state][y][x];
  
  long long sum = 0;
  switch (state) {
  case 1:
    if (isValid(1, y, x + 1))
      sum += dp(1, y, x + 1);
    if (isValid(3, y, x + 1))
      sum += dp(3, y, x + 1);
    break;
  case 2:
    if (isValid(2, y + 1, x))
      sum += dp(2, y + 1, x);
    if (isValid(3, y + 1, x))
      sum += dp(3, y + 1, x);
    break;
  case 3:
    for (int i = 1; i <= 3; i++)
      if (isValid(i, y + 1, x + 1))
          sum += dp(i, y + 1, x + 1);
    break;
  }
  
  return lut[state][y][x] = sum;
}

void initLut() {
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < N; j++) 
      lut[1][i][j] = lut[2][i][j] = lut[3][i][j] = -1;

  lut[1][N - 1][N - 2] = map[N-1][N-2] != WALL;
  lut[2][N - 2][N - 1] = map[N-2][N-1] != WALL;
  lut[3][N - 2][N - 2] = map[N-2][N-2] != WALL;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) 
    for (int j = 0; j < N; j++) 
      cin >> map[i][j];

  initLut();

  cout << dp(1, 0, 0) << endl;

  return 0;
}
