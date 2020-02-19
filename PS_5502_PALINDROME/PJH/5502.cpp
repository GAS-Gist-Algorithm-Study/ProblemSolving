#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

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
