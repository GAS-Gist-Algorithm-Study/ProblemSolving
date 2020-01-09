#include <iostream>
#include <cstring>

using namespace std;

int R, C, T;
int cleanerR, cleanerC;
int room[50][50];
int temp[50][50];

int sumDust();
void diffuse();
bool areValid(int, int);
void cleanerOperate();

int main() {
  bool isCleanerFound = false;
  cin >> R >> C >> T;

  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++) {
      cin >> room[r][c];
      if (!isCleanerFound && room[r][c] == -1) {
        cleanerR = r;
        cleanerC = c;
        isCleanerFound = true;
      }
    }

  while (T--) {
    diffuse();
    cleanerOperate();
  }
    
  cout << sumDust() << endl;
  return 0;
}

void cleanerOperate() {
  // upper part
  room[cleanerR][1] = 0;
  for (int c = 2; c < C; c++) 
    room[cleanerR][c] = temp[cleanerR][c - 1];

  for (int r = cleanerR - 1; r >= 0; r--)
    room[r][C -1] = temp[r + 1][C - 1];

  for (int c = C - 2; c >= 0; c--) 
    room[0][c] = temp[0][c + 1];

  for (int r = 1; r < cleanerR; r++)
    room[r][0] = temp[r - 1][0];

  // lower part
  room[cleanerR + 1][1] = 0;
  for (int c = 2; c < C; c++) 
    room[cleanerR + 1][c] = temp[cleanerR + 1][c - 1];

  for (int r = cleanerR + 2; r < R; r++)
    room[r][C - 1] = temp[r - 1][C - 1];

  for (int c = C - 2; c >= 0; c--) 
    room[R - 1][c] = temp[R - 1][c + 1];

  for (int r = R - 2; r > cleanerR + 1; r--)
    room[r][0] = temp[r + 1][0];
}

void diffuse() {
  int dr[4] = { -1, 1, 0, 0 };
  int dc[4] = { 0, 0, -1, 1 };

  memset(temp, 0, sizeof(int) * 50 * 50);
  temp[cleanerR][cleanerC] = -1;
  temp[cleanerR + 1][cleanerC] = -1;

  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++) {
      int newr, newc;
      int A = room[r][c];
      int dA = A / 5;
      int cntDiffused = 0;

      if (A == -1 || A == 0) 
        continue;

      for (int i = 0; i < 4; i++) {
        newr = r + dr[i];
        newc = c + dc[i];
        if (!areValid(newr, newc) 
            || room[newr][newc] == -1)
          continue;

        temp[newr][newc] += dA;
        cntDiffused++;
      }

      temp[r][c] += A - dA * cntDiffused;
    }

  memcpy(room, temp, sizeof(int) * 50 * 50);
}

bool areValid(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

int sumDust() {
  int sum = 0;
  for (int i = 0; i < 50; i++) 
    for (int j = 0; j < 50; j++) 
      sum += room[i][j];

  sum += 2;

  return sum;
}
