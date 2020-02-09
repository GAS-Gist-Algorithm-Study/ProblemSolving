#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> makeTable(const string& pattern) 
{
  int j = 0;
  int patternSize = pattern.size();
  vector<int> table(patternSize, 0);

  for (int i = 1; i < patternSize; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = table[j - 1];
    }
    if (pattern[i] == pattern[j])
      table[i] = ++j;
  }
  
  return table;
}

vector<int> KMP(const string& text, const string& pattern)
{
  vector<int> indices;
  vector<int> table = makeTable(pattern);
  int n = text.size();
  int m = pattern.size();
  int j = 0;

  for (int i = 0; i < n; i++) {
    while (j > 0 && text[i] != pattern[j])
      j = table[j - 1];

    if (pattern[j] == text[i]) {
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

int main(void) 
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
