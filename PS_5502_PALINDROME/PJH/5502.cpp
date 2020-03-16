#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
int LCS(string str1, string str2)
{
  int len1 = str1.size();
  int len2 = str2.size();
  int lut[len1 + 1][len2 + 1] = { 0, };

  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      if (i == 0 || j == 0)
        lut[i][j] = 0;
      else if (str1[i - 1] == str2[j - 1]) 
        lut[i][j] = 1 + lut[i - 1][j - 1];
      else 
        lut[i][j] = max(lut[i - 1][j], lut[i][j - 1]);
    }
  }

  return lut[len1][len2];
}
*/

int _LCS(const string& str1, const string& str2, int i, int j, int** lut)
{
  if (lut[i][j] != -1)
    return lut[i][j];

  if (i == 0 || j == 0)
    return lut[i][j] = 0;

  if (str1[i - 1] == str2[j - 1])
    return lut[i][j] = 1 + _LCS(str1, str2, i - 1, j - 1, lut);
  return lut[i][j] = max(
      _LCS(str1, str2, i - 1, j, lut), _LCS(str1, str2, i, j -1, lut)
      );
}

int LCS(string str1, string str2)
{
  int** lut = (int**)malloc((str1.size() + 1) * sizeof(int*));
  for (int i = 0; i <= str1.size(); i++)
    lut[i] = (int*)malloc((str2.size() + 1) * sizeof(int));


  return _LCS(str1, str2, str1.size(), str2.size(), lut);
}

int main(void)
{
  int N;
  string text;

  cin >> N
      >> text;

  string reversed(text);
  reverse(text.begin(), text.end());

  cout << text.size() - LCS(text, reversed) << endl;
  return 0;
}
