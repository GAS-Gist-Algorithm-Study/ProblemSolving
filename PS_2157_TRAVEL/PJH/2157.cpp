#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>

typedef std::pair<int, int> edge;
#define point first
#define src second
#define IMPOSIBBLE -2

using namespace std;

int findMaxRoute(
    const vector<edge> nodes[], 
    int** lut, 
    int N, int M
    )
{
  if (lut[N][M] != -1)
    return lut[N][M];

  int maxPoint = -1;
  
  for (const edge& e: nodes[N]) {
    int partialMax = findMaxRoute(nodes, lut, e.src, M - 1);
    if (partialMax != IMPOSIBBLE) {
      int partialSum = partialMax + e.point;
      if (partialSum > maxPoint)
        maxPoint = partialSum;
    }
  }

  if (maxPoint == -1)
    return lut[N][M] = IMPOSIBBLE;

  return lut[N][M] = maxPoint;
}

int findMaxRoute(const vector<edge> nodes[], int N, int M)
{
  int** lut = (int**) malloc(sizeof(int*) * (N + 1));
  for (int i = 0; i <= N; i++)
    lut[i] = (int*) malloc(sizeof(int) * (M + 1));

  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= M; j++)
      lut[i][j] = -1;

  for (int j = 2; j <= N; j++)
    lut[j][1] = lut[j][0] IMPOSIBBLE;

  for (int i = 1; i <= M; i++)
    lut[1][i] = 0;

  lut[0][0] = IMPOSIBBLE;
  lut[1][0] = IMPOSIBBLE;
  
  return findMaxRoute(nodes, lut, N, M);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, K;
  cin >> N >> M >> K;

  vector<edge> nodes[N + 1];
  for (int k = 0; k < K; k++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a < b) 
      nodes[b].emplace_back(c, a);
  }

  cout << findMaxRoute(nodes, N, M) << '\n';
  return 0;
}
