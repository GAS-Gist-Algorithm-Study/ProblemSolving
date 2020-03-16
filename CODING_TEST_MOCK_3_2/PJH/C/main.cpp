#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#define yx pair<int, int>
#define y first
#define x second

using namespace std;

struct group
{
  int numStones = 0;
  set<yx> toCover;
};

void makeGroup(group& newGroup, int** map, int i, int j, int N, int M)
{
  if (i >= N || i < 0 || j >= M || j < 0)
    return;

  if (map[i][j] == 2) {
    map[i][j] = -2;
    newGroup.numStones++;
    
    makeGroup(newGroup, map, i + 1, j, N, M);
    makeGroup(newGroup, map, i - 1, j, N, M);
    makeGroup(newGroup, map, i, j + 1, N, M);
    makeGroup(newGroup, map, i, j - 1, N, M);
  } else if (map[i][j] == 0) {
    newGroup.toCover.emplace(i, j);
  }
}

pair<vector<group>, vector<group> > getGroups(int**map, int N, int M)
{
  vector<group> ones;
  vector<group> twos;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] == 2) {
        group newGroup;
        makeGroup(newGroup, map, i, j, N, M);
        if (newGroup.toCover.size() == 1) {
          ones.emplace_back(newGroup);
        } else if (newGroup.toCover.size() == 2) {
          twos.emplace_back(newGroup);
        }
      }
    }
  }

  return {ones, twos};
}

int** makeMap(int N, int M)
{
  int** map = (int**) malloc(sizeof(int*) * N);;
  for (int i = 0; i < N; i++) 
    map[i] = (int*) malloc(sizeof(int) * M);

  return map;
}

void checkOnes(int** scores, const vector<group>& ones, int& maxNum, int N, int M)
{
  vector<int> nums;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (scores[i][j] != 0)
        nums.push_back(scores[i][j]);

  sort(nums.begin(), nums.end(), greater<int>());
  if (nums.size() == 0)
    return;
  if (nums.size() == 1)
    maxNum = max(maxNum, nums[0]);
  else
    maxNum = max(maxNum, nums[0] + nums[1]);
}

void checkTwos(int** scores, const vector<group>& twos, int& maxNum, int N, int M)
{
  set<yx> toCoverTotal;
  map<yx, vector<int>> toConsider;

  int n = twos.size();
  vector<int> numLefts(n);
  fill(numLefts.begin(), numLefts.end(), 2);

  for (int i = 0; i < n; i++) {
    const group& g = twos[i];
    
    for (const yx& loc: g.toCover) 
      toConsider[loc].push_back(i);
  }

  for (const group& g: twos) {
    int num = 0;
    for (const yx& loc: g.toCover) {
      for (int i: toConsider[loc]) {
        numLefts[i]--;
        if (numLefts[i] == 0)
          num += twos[i].numStones;
      }

      num += scores[loc.y][loc.x];
    }

    for (const yx& loc: g.toCover) {
      for (int i: toConsider[loc]) 
        numLefts[i]++;
    }

    maxNum = max(maxNum, num);
  }
}

void spreadOnes(int** scores, const vector<group>& ones, int N, int M)
{
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      scores[i][j] = 0;

  for (const group& g: ones) 
    for (const yx& loc: g.toCover) 
      scores[loc.y][loc.x] += g.numStones;
}

int solve(int** map, int N, int M)
{
  pair<vector<group>, vector<group> > groups = getGroups(map, N, M);

  vector<group>& ones = groups.first;
  vector<group>& twos = groups.second;

  int** scores = makeMap(N, M);
  spreadOnes(scores, ones, N, M);
  
  int maxNum = 0;

  checkOnes(scores, ones, maxNum, N, M);
  checkTwos(scores, twos, maxNum, N, M);

  return maxNum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, M;
  cin >> N >> M;

  int** map = makeMap(N, M);

  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      cin >> map[i][j];

  cout << solve(map, N, M) << '\n';
  return 0;
}
