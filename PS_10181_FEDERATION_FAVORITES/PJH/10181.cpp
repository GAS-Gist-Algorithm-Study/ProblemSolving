#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void showDivs(int n, vector<int> & divs)
{
  cout << n << " = " << divs[0];

  for (int i = 1; i < divs.size(); i++)
    cout << " + " << divs[i];

  endl(cout);
}

void solve(int n) 
{
  vector<int> divs;

  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0)
      divs.push_back(i);
  }

  int sum = accumulate(divs.begin(), divs.end(), 0);

  if (sum == n) 
    showDivs(n, divs);
  else 
    cout << n << " is NOT perfect." << endl;
}

int main() 
{
  while (true) {
    int n;
    cin >> n;

    if (n == -1)
      break;

    solve(n);
  }

  return 0;
}
