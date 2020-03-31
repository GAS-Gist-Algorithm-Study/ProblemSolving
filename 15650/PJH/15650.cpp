#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

void backtrack(bool used[], int stack[], int N, int M, int top, int last)
{
  if (M == 0) {
    for (int i = 0; i < top; i++)
      cout << stack[i] << " ";
    cout << endl;
    return;
  }
    
  for (int i = last + 1; i <= N; i++) {
    stack[top] = i;
    used[i] = true;
    backtrack(used, stack, N, M - 1, top + 1, i);
    used[i] = false;
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  bool used[N + 1] = { 0, };
  int stack[N];

  backtrack(used, stack, N, M, 0, 0);
  return 0;
}

