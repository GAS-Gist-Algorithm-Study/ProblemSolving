#include <iostream>
#include <string>

using namespace std;

int lut[1001][1001];

int _LCS(const string& str1, const string& str2,
         int i, int j)
{
  if (lut[i][j] != -1)
    return lut[i][j];

  if (i == 0 || j == 0)
    return lut[i][j] = 0;
  
  if (str1[i - 1] == str2[j - 1]) 
    return lut[i][j] = 1 + _LCS(str1, str2, i - 1, j - 1);
  
  int _max = max(_LCS(str1, str2, i, j - 1), _LCS(str1, str2, i - 1, j));
  return lut[i][j] = _max;
}

int LCS(const string& str1, const string& str2)
{
  int len1 = str1.size();
  int len2 = str2.size();

  for (int i = 0; i <= len1; i++)
    for (int j = 0; j <= len2; j++)
      lut[i][j] = -1;

  return _LCS(str1, str2, len1, len2);
}

int main() 
{
  string str1;
  string str2;

  cin >> str1 >> str2;
  cout << LCS(str1, str2) << endl;

  return 0;
}
