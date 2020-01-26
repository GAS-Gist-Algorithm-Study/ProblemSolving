#include <iostream>
#include <vector>
#define WALL true
#define YX pair<int, int>
#define Y first
#define X second
#define DY first
#define DX second

using namespace std;

int N;
bool map[16][16];
int state = 1;
YX origin = { 0, 0 };

vector<vector<YX>> dydxs = {
  { {0, 0}, {0, 1} },
  { {0, 0}, {0, 1}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0} }
};

bool hasPipeArrived() {
  switch (state) {
  case 1:
    return (origin.Y == N - 1 && origin.X == N - 2);
    break;
  case 2:
    return (origin.Y == N - 2 && origin.X == N - 2);
    break;
  case 3:
    return (origin.Y == N - 2 && origin.X == N - 1);
    break;
  }
  
  return false;
}

bool isPipeValid() {
  for (YX dydx: dydxs[state - 1]) {
    int newy = origin.Y + dydx.DY;
    int newx = origin.X + dydx.DX;

    if ((newy < 0 || newy >= N || newx < 0 || newx >= N)
      || (map[newy][newx] == WALL))
      return false;
  }

  return true;
}

int dfs() 
{
  if (hasPipeArrived())
    return 1;

  int sum = 0;

  switch (state) {
  case 1:
    origin = { origin.Y, origin.X + 1};
    if (isPipeValid())
      sum += dfs();
    origin = { origin.Y, origin.X - 1};

    origin = { origin.Y, origin.X + 1};
    state = 2;
    if (isPipeValid())
      sum += dfs();
    state = 1;
    origin = { origin.Y, origin.X - 1};

    break;
  case 2:
    origin = { origin.Y + 1, origin.X + 1};
    if (isPipeValid())
      sum += dfs();
    origin = { origin.Y - 1, origin.X - 1};

    origin = { origin.Y + 1, origin.X + 1};
    state = 1;
    if (isPipeValid())
      sum += dfs();
    state = 2;
    origin = { origin.Y - 1, origin.X - 1};

    origin = { origin.Y + 1, origin.X + 1};
    state = 3;
    if (isPipeValid())
      sum += dfs();
    state = 2;
    origin = { origin.Y - 1, origin.X - 1};

    break;
  case 3:
    origin = { origin.Y + 1, origin.X};
    if (isPipeValid())
      sum += dfs();
    origin = { origin.Y - 1, origin.X };

    origin = { origin.Y + 1, origin.X };
    state = 2;
    if (isPipeValid())
      sum += dfs();
    state = 3;
    origin = { origin.Y - 1, origin.X };

    break;
  }

  return sum;
}

int main() 
{
  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> map[i][j];

  cout << dfs() << endl;
  return 0;
}
