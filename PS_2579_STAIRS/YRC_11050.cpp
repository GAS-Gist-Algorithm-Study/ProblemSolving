#include <iostream>
#include <vector>

using namespace std;
int factorial[12];
int N,K;


int fact(int n){
  if(n==0)
    return factorial[n] = 1;

  if(factorial[n]!=0)
    return factorial[n];

  else return factorial[n] = n*fact(n-1);

}


int main (){
  cin >> N >> K;
  cout << fact(N)/(fact(K)*fact(N-K))<<endl;
}
