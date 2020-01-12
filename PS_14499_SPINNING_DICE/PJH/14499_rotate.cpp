#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int map[20][20];
int N, M, x, y, K;
vector<int> order;
vector<int> ans;

int diceX[4];
int diceY[4];

void input();
void solve();
void output();
bool isLegalMove(int);
void move(int);
void roll(int);

int main() {
  input();
  solve();
  output();
  return 0;
}

bool isLegalMove(int dir) {
  switch (dir) {
  case 1:
    return x < M - 1;
  case 2:
    return x > 0;
  case 3:
    return y > 0;
  case 4:
    return y < N - 1;
  default:
    return false;
  }
}

void move(int dir) {
  switch (dir) {
  case 1:
    x++;
    break;
  case 2:
    x--;
    break;
  case 3:
    y--;
    break;
  case 4:
    y++;
    break;
  }
}

void roll(int dir) {
  int temp = 0;
  switch (dir) {
  case 1: // east
    rotate(diceX, diceX + 3, diceX + 4);

    diceY[1] = diceX[1];
    diceY[3] = diceX[3];
    break;

  case 2: // west
    rotate(diceX, diceX + 1, diceX + 4);

    diceY[1] = diceX[1];
    diceY[3] = diceX[3];
    break;

  case 3: // north
    rotate(diceY, diceY + 1, diceY + 4);

    diceX[1] = diceY[1];
    diceX[3] = diceY[3];
    break;

  case 4: // south
    rotate(diceY, diceY + 3, diceY + 4);

    diceX[1] = diceY[1];
    diceX[3] = diceY[3];
    break;
  }
}

void solve() {
  for (int dir: order) {
    if (!isLegalMove(dir))
      continue;

    move(dir);
    roll(dir);

    if (map[y][x] == 0) {
      map[y][x] = diceY[3];
    } else {
      diceY[3] = map[y][x];
      diceX[3] = map[y][x];
      map[y][x] = 0;
    }

    ans.push_back(diceY[1]);
  }
}

void input() {
  cin >> N >> M >> y >> x >> K;

  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      cin >> map[i][j];

  order.resize(K);
  for (int i = 0; i < K; i++) 
    cin >> order[i];
}

void output() {
  for (int n: ans)
    cout << n << endl;
}
