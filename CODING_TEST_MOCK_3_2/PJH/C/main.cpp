#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define yx pair<int, int>
#define y first
#define x second

using namespace std;

struct Group
{
  int left;
  int numStones = 0;
  set<yx> toCover;

  bool operator < (const Group& g) const {
    return toCover.size() > g.toCover.size();
  }
};

bool bfs(vector<vector<int> >& map, int N, int M, int i, int j, Group& newGroup)
{
  bool worthy = true;
  queue<yx> q;
  q.emplace(i, j);
 
  while (!q.empty()) {
    yx target = q.front();
    q.pop();

    if (target.y >= N || target.y < 0 
        || target.x >= M || target.x < 0)
      continue;
    
    switch (map[target.y][target.x]) {
    case 2:
      map[target.y][target.x] = -2; // visited
      newGroup.numStones++;
      q.emplace(target.y, target.x + 1);
      q.emplace(target.y, target.x - 1);
      q.emplace(target.y + 1, target.x);
      q.emplace(target.y - 1, target.x);
      break;

    case 0:
      newGroup.toCover.emplace(target);
      if (newGroup.toCover.size() > 2)
        return false;
      break;
    }
  }

  return worthy;
}

void getGroups(vector<Group>& groups, int N, int M, vector<vector<int> >& map)
{
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      if (map[i][j] == 2) {
        groups.emplace_back();
        if (!bfs(map, N, M, i, j, groups[groups.size() - 1]))
          groups.pop_back();
      }
}

int solve(int N, int M, vector<vector<int> >& map)
{
  vector<Group> opponentGroups;
  getGroups(opponentGroups, N, M, map);

  sort(opponentGroups.begin(), opponentGroups.end());
  
  int n = opponentGroups.size();
  int toCoverLeft[n];
  for (int i = 0; i < n; i++)
    toCoverLeft[i] = opponentGroups[i].toCover.size();

  vector<int> table[N][M];
  set<yx> totalToCovers;

  for (int i = 0; i < n; i++) 
    for (auto hole: opponentGroups[i].toCover) {
      table[hole.y][hole.x].push_back(i);
      totalToCovers.emplace(hole);
    }
  
  vector<yx> locs;
  for (auto a: totalToCovers)
    locs.emplace_back(a);

  int T = locs.size();
  int maxSum = 0;
  if (T < 2) {
    if (T == 1) {
      yx loc = locs[0];

      int sum = 0;
      for (auto a: table[loc.y][loc.x])
        sum += opponentGroups[a].numStones;
      
      return sum;
    } else //if (T == 0) 
      return 0;
  } else {
    int scores[N][M] = {0,};
    for (int i = 0; i < N; i++)
      for (int j = 0 ;j < M; j++)
        scores[i][j] = 0;
    int i = 0;
    for (; i < n; i++) {
      int sum = 0;
      if (opponentGroups[i].toCover.size() == 2) {
        for (const yx& loc: opponentGroups[i].toCover) {
          for (int i: table[loc.y][loc.x]) {
            toCoverLeft[i]--;
            if (toCoverLeft[i] == 0)
              sum += opponentGroups[i].numStones;
          }
        }
        maxSum = max(maxSum, sum);

        for (const yx& loc: opponentGroups[i].toCover) 
          for (int i: table[loc.y][loc.x]) 
            toCoverLeft[i]++;
      } else { // == 1
        break;
      }
    }

    for (int j = i; j < n; j++) {
      for (const yx& loc: opponentGroups[j].toCover) {
        scores[loc.y][loc.x] += opponentGroups[j].numStones;
      }
    }

    vector<int> tempScores;

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (scores[i][j] != 0)
          tempScores.push_back(scores[i][j]);

    sort(tempScores.begin(), tempScores.end());

    if (tempScores.size() > 1) 
      maxSum = max(maxSum, tempScores[tempScores.size() - 1] + tempScores[tempScores.size() - 2]);
    else if (tempScores.size())
      maxSum = max(maxSum, tempScores[tempScores.size() - 1]);
  }

  return maxSum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<vector<int> > map;
  map.resize(N);
  for (auto& vi: map)
    vi.resize(M);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> map[i][j];

  cout << solve(N, M, map) << endl;
  return 0;
}
  
