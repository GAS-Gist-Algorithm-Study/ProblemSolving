#include <iostream>
#include <algorithm>
#include <vector>
#define egg pair<int, int>
#define shield first
#define weight second

using namespace std;

void dfs(int N, int& maxCount, egg eggs[], int index)
{
  if (index == N) {
    int count = 0;
    for (int i = 0; i < N; i++) 
      if (eggs[i].shield <= 0)
        count++;
    
    maxCount = max(maxCount, count);
    return;
  } 

  egg& onHand = eggs[index];
  vector<int> unbrokens; 

  for (int i = 0; i < N; i++)
    if (eggs[i].shield > 0 && i != index)
      unbrokens.push_back(i);
  
  if (onHand.shield <= 0 || unbrokens.size() == 0) {
    dfs(N, maxCount, eggs, index + 1);    
    return;
  } 

  for (int i: unbrokens) {
    eggs[i].shield -= onHand.weight;
    onHand.shield -= eggs[i].weight;

    dfs(N, maxCount, eggs, index + 1);

    eggs[i].shield += onHand.weight;
    onHand.shield += eggs[i].weight;
  }

}

int solve(int N, egg eggs[])
{
  int maxCount = 0;

  dfs(N, maxCount, eggs, 0);
  return maxCount;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  egg eggs[N];
  for (int i = 0; i < N; i++) 
    cin >> eggs[i].shield
        >> eggs[i].weight;
  
  cout << solve(N, eggs) << endl;
  return 0;
}
