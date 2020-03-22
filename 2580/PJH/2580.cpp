#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define yx pair<int, int>
#define y first
#define x second

using namespace std;

void getMap(int map[][9])
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> map[i][j];
}

void printMap(int map[][9])
{ 
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      cout << map[i][j] << " ";

    cout << endl;
  }
}

void checkVertical(int map[][9], yx loc, bool cantUse[])
{
  for (int i = 0; i < 9; i++) 
    cantUse[map[i][loc.x]] = true;
}

void checkHorizontal(int map[][9], yx loc, bool cantUse[])
{
  for (int i = 0; i < 9; i++) 
    cantUse[map[loc.y][i]] = true;
}

void checkBox(int map[][9], yx loc, bool cantUse[])
{
  int Y = (loc.y / 3) * 3;
  int X = (loc.x / 3) * 3;

  for (int i = Y; i < Y + 3; i++) 
    for (int j = X; j < X + 3; j++) 
      cantUse[map[i][j]] = true;
}

vector<int> getCandidates(int map[][9], yx loc)
{
  vector<int> candidates;
  bool cantUse[10] = { 0, };

  checkVertical(map, loc, cantUse);
  checkHorizontal(map, loc, cantUse);
  checkBox(map, loc, cantUse);

  for (int i = 1; i <= 9; i++) 
    if (!cantUse[i])
      candidates.push_back(i);

  return candidates;
}

bool backtrack(int map[][9], const vector<yx>& zeros, int i, int N)
{
  if (i == N) {
    return true;
  }

  yx loc = zeros[i];
  vector<int> candidates = getCandidates(map, loc);

  for (int num: candidates) {
    map[loc.y][loc.x] = num;
    if (backtrack(map, zeros, i + 1, N))
      return true;
    map[loc.y][loc.x] = 0;
  }
  
  return false;
}

void fillMap(int map[][9])
{
  vector<yx> zeros;

  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (map[i][j] == 0)
        zeros.emplace_back(i, j);

  backtrack(map, zeros, 0, zeros.size());
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int map[9][9];
  getMap(map);
  fillMap(map);
  printMap(map);
  return 0;
}

