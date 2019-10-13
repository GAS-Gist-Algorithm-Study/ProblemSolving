#include <iostream>
#include <vector>

using namespace std;
int N;
int stepscore[301][301];

int cal1[301];
int cal2[301];

int score(int n){
  if(n==0)
    return cal[0] = 0;

  if(n==1)
    return cal[n] = stepscore[n];

  if(n==2)
    return stepscore[n]+stepscore[n-1];

  if(cal[n-1] == stepscore[n-1]+cal[n-2])
    return cal[n] = max(cal[n-2]+stepscore[n],)




}


int main (){
  cin >> N;
  for(int i=0;i<N;i++)
    cin>> stepscore[i];

    cal1[1] = cal2[1] = 1;






}
