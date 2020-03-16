#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> makeTable(string pattern)
{
  int m = pattern.size();
  int j = 0;
  vector<int> table(m, 0);

  for (int i = 1; i < m; i++) {
    while (j > 0 && pattern[i] != pattern[j])
      j = table[j - 1];

    if (pattern[i] == pattern[j])
      table[i] = ++j;
  }

  return table;
}

vector<int> KMP(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  int j = 0;
  vector<int> indices;
  vector<int> table = makeTable(pattern);

  for (int i = 0; i < n; i++) {
    while (j > 0 && text[i] != pattern[j])   
      j = table[j - 1];

    if (text[i] == pattern[j]) {
      if (j == m - 1) {
        indices.push_back(i - m + 2);
        j = table[j];
      } else {
        j++;
      }
    }


  }

  return indices;
}

int main() 
{
  string text, pattern;
  getline(cin, text);
  getline(cin, pattern);

  vector<int> indices = KMP(text, pattern);
  cout << indices.size() << endl;
  for (int index: indices)
    cout << index << " ";
  endl(cout);
  
  return 0;
}
