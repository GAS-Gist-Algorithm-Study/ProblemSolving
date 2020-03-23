#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int getOpponentAbility(int N, bool picked[], int ability[][20])
{
  vector<int> lineup_opp;
  for (int i = 0; i < N; i++)
    if (!picked[i])
      lineup_opp.push_back(i);

  int totalAbility = 0;
  for (int i: lineup_opp)
    for (int j: lineup_opp)
      totalAbility += ability[i][j];

  return totalAbility;
}

void backtrack(int step, int N, int nowSum, 
    vector<int>& lineup, int ability[][20], bool picked[], int& minGap)
{
  if (step == N / 2) {
    int opponentTeamAbility = getOpponentAbility(N, picked, ability);
    int gap = abs(nowSum - opponentTeamAbility);

    minGap = min(minGap, gap);
    return;
  }

  int start = lineup.size() ? lineup.back() : 0;

  for (int i = start; i < N; i++) {
    if (picked[i])
      continue;

    for (int j: lineup)
      nowSum += ability[i][j];
    for (int j: lineup)
      nowSum += ability[j][i];

    lineup.push_back(i);
    picked[i] = true;

    backtrack(step + 1, N, nowSum, lineup, ability, picked, minGap);

    picked[i] = false;
    lineup.pop_back();
    for (int j: lineup)
      nowSum -= ability[i][j];
    for (int j: lineup)
      nowSum -= ability[j][i];
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int ability[20][20];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> ability[i][j];

  bool picked[N] = {0,};
  int minGap = 987654321;
  vector<int> lineup;
  backtrack(0, N, 0, lineup, ability, picked, minGap);
  cout << minGap << endl;
  return 0;
}
