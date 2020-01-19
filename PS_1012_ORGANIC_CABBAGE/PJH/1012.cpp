#include <iostream>
#include <vector>
#define CABBAGE true

using namespace std;

struct node 
{
  node() {visited = false;}
  bool visited;
  vector<node*> neighbors;
};

int countClusters(bool[50][50], int, int, int);
bool areValid(int, int, int, int);
int DFS(node*);

int main() 
{
  int T;
  cin >> T;

  while (T--) {
    int M, N, K;
    int X, Y;
    bool ground[50][50] = { 0, };

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
      cin >> X >> Y;
      ground[Y][X] = CABBAGE;
    }

    cout << countClusters(ground, M, N, K) << endl;
  }

  return 0;
}

bool areValid(int x, int y, int M, int N) 
{
  return x >= 0 && x < M && y >= 0 && y < N;
}

int countClusters(bool ground[50][50], int M, int N, int K) 
{
  int cnt = 0;
  node* nodes[N][M];
  vector<node*> cabbageNodes;

  int dxs[4] = { -1, 1, 0, 0 };
  int dys[4] = { 0, 0, 1, -1 };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      nodes[i][j] = new node();
      if (ground[i][j] == CABBAGE)
        cabbageNodes.push_back(nodes[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (ground[i][j] != CABBAGE)
        continue;

      for (int k = 0; k < 4; k++) {
        int newx = j + dxs[k];
        int newy = i + dys[k];
        if (!areValid(newx, newy, M, N))
          continue;

        if (ground[newy][newx] == CABBAGE)
          nodes[i][j]->neighbors.push_back(nodes[newy][newx]);
      }
    }
  }
  
  while (K > 0) {
    cnt++;
    
    for (node* cab: cabbageNodes) {
      if (!cab->visited) {
        K -= DFS(cab);
        break;
      }
    }
  }

  return cnt;
}

int DFS(node* root) 
{
  int cnt = (root->visited == false);
  root->visited = true;

  for (node* next: root->neighbors) {
    if (next->visited)
      continue;
    cnt += DFS(next);
  }
  
  return cnt;
}
