#include <cstdio>
#include <queue>
#include <algorithm>

#define HIJ 10000 * h + 100 * i + j

int boxes[1000000];
int H, N, M;

void print()
{
  for (int h = 0; h < H; h++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++)
        printf("%d ", *(boxes + HIJ));

      printf("\n");
    }
    printf("\n");
  }

  printf("---------------------\n");
}

int countZero()
{
  int cnt = 0;

  for (int h = 0; h < H; h++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (*(boxes + HIJ) == 0)
          cnt++;

  return cnt;
}

void initQ(std::queue<int>& q)
{
  for (int h = 0; h < H; h++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (*(boxes + HIJ) == 1)
          q.push(HIJ);
}

bool isValid(int h, int i, int j, int step)
{
  if (h < 0 || h >= H
      || i < 0 || i >= N
      || j < 0 || j >= M)
    return false;

  if (boxes[HIJ])
    return false;

  return true;
}

bool ripe(int h, int i, int j, int step)
{
  if (!isValid(h, i, j, step))
    return false;

  boxes[HIJ] = step;
  return true;
}

int tomato()
{
  int zeros = countZero();
  std::queue<int> q;
  
  initQ(q);
  
  int cnt = 0;
  int maxStep = 0;

  int dhs[6] = { 1, -1, 0, 0, 0, 0 };
  int dis[6] = { 0, 0, 1, -1, 0, 0 };
  int djs[6] = { 0, 0, 0, 0, 1, -1 };

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    int h = now / 10000;
    now %= 10000;
    int i = now / 100;
    now %= 100;
    int j = now;

    int step = boxes[HIJ];
    for (int k = 0; k < 6; k++) {
      int newh = h + dhs[k];
      int newi = i + dis[k];
      int newj = j + djs[k];

      if (ripe(newh, newi, newj, step + 1)) {
        cnt++;
        q.push(newh * 10000 + newi * 100 + newj);
        maxStep = step;
      }
    }
  }

  if (cnt == zeros)
    return maxStep;
  else 
    return -1;
}

int main(void)
{
  scanf("%d %d %d", &M, &N, &H);

  for (int h = 0; h < H; h++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        scanf("%d", boxes + HIJ);

  printf("%d\n", tomato());
  return 0;
}
