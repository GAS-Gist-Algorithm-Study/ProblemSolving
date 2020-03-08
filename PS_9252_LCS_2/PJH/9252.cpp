#include <iostream>
#include <string>

using namespace std;

string findLCS(int** lut, const string& str1,
    int size1, int size2)
{
  string ans = "";

  int i = size1, j = size2;
  while (i > 0 && j > 0) {
    if (lut[i][j] == lut[i][j - 1])
      j--;
    else if (lut[i][j] == lut[i - 1][j])
      i--;
    else if (lut[i][j] == lut[i - 1][j - 1] + 1) {
      ans = str1[i - 1] + ans;
      i--;
      j--;
    }
  }

  return ans;
}

string LCS(const string& str1, const string& str2)
{
  int size1 = str1.size();
  int size2 = str2.size();
  
  int** lut = (int**) malloc(sizeof(int*) * (size1 + 1));
  for (int i = 0; i <= size1; i++)
    lut[i] = (int*) malloc(sizeof(int) * (size2 + 1));

  for (int i = 0; i < size1 + 1; i++)
    lut[i][0] = 0;
  for (int j = 0; j < size2 + 1; j++)
    lut[0][j] = 0;

  for (int i = 1; i < size1 + 1; i++)
    for (int j = 1; j < size2 + 1; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        lut[i][j] = 1 + lut[i - 1][j - 1];
      } else {
        lut[i][j] = max(
            lut[i][j - 1], 
            lut[i - 1][j]
        );
      }
    }

  return findLCS(lut, str1, size1, size2);
}

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string str1, str2;
  cin >> str1 >> str2;

  string ans = LCS(str1, str2);
  cout << ans.size() << '\n';
  cout << ans << '\n';
  return 0;
}
