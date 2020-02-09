#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int lut[2000][2000];

bool isPalindrome(const vector<int>& text, int s, int e)
{
  if (lut[s][e] != -1)
    return lut[s][e];
  
  if (s + 1 == e)
    return lut[s][e] = text[s] == text[e];

  return lut[s][e] 
    = (text[s] == text[e]) && isPalindrome(text, s + 1, e - 1);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  vector<pii> questions;

  cin >> N;
  vector<int> text(N, 0);
  for (int i = 0; i < N; i++)
    cin >> text[i];

  cin >> M;
  int s, e;
  for (int i = 0; i < M; i++) {
    cin >> s >> e;
    questions.emplace_back(s - 1, e - 1);
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      lut[i][j] = -1;
  for (int i = 0; i < N; i++)
    lut[i][i] = 1;
  
  for (auto q: questions)
    cout << (isPalindrome(text, q.first, q.second) ? 1 : 0) << '\n';

  return 0;
}
