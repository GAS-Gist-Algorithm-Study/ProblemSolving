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

struct group
{
  vector<yx> stones;
  set<yx> toCover;
};

void bfs(vector<vector<int> >& map, 
        int N, int M, 
        int i, int j, 
        group& newGroup)
{
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
      newGroup.stones.emplace_back(target);
      q.emplace(target.y, target.x + 1);
      q.emplace(target.y, target.x - 1);
      q.emplace(target.y + 1, target.x);
      q.emplace(target.y - 1, target.x);
      break;

    case 0:
      newGroup.toCover.emplace(target);
      break;
    }
  }
}

void getGroups(vector<group>& groups, int N, int M, vector<vector<int> > map)
{
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      if (map[i][j] == 2) {
        groups.emplace_back();
        bfs(map, N, M, i, j, groups[groups.size() - 1]);
      }
}

int solve(int N, int M, const vector<vector<int> >& map)
{
  vector<group> opponentGroups;
  getGroups(opponentGroups, N, M, map);
  
  vector<group> possibleGroups;
  copy_if(
      opponentGroups.begin(),
      opponentGroups.end(),
      back_inserter(possibleGroups),
      [](const group& g) {
        return g.toCover.size() <= 2;
      });
    
  int n = possibleGroups.size();
  int toCoverLeft[n];
  for (int i = 0; i < n; i++)
    toCoverLeft[i] = possibleGroups[i].toCover.size();

  vector<int> table[N][M];
  set<yx> totalToCovers;

  for (int i = 0; i < n; i++) 
    for (auto hole: possibleGroups[i].toCover) {
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
      for (auto a: table[loc.y][loc.x]) {
        sum += possibleGroups[a].stones.size();
      }
      
      return sum;
    } else if (T == 0) {
      return 0;
    }
    
  } else {

    for (int i = 0; i < T; i++) {
      int sum = 0;

      yx loci = locs[i];
      for (auto a: table[loci.y][loci.x]) {
        toCoverLeft[a]--;
        if (toCoverLeft[a] == 0)
          sum += possibleGroups[a].stones.size();
      }

      for (int j = i + 1; j < T; j++) {
        yx locj = locs[j];

        for (auto a: table[locj.y][locj.x]) {
          toCoverLeft[a]--;
          if (toCoverLeft[a] == 0) 
            sum += possibleGroups[a].stones.size();
        }
        
        maxSum = max(maxSum, sum);

        for (auto a: table[locj.y][locj.x]) {
          toCoverLeft[a]++;
          if (toCoverLeft[a] == 1) 
            sum -= possibleGroups[a].stones.size();
        }
      }

      for (auto a: table[loci.y][loci.x]) {
        toCoverLeft[a]++;
      }
    }
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
  
