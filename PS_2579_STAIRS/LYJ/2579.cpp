#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,t;
    cin >> n;

    int stepScore[301] = {0,};
    int maxSum[301]={0,};

    for(int i=1;i<=n;i++){
        cin >> t;
        stepScore[i]=t;
    }

    if(n==1)maxSum[1]=stepScore[1];
    else if(n==2){
        maxSum[1]=stepScore[1];
        maxSum[2]=maxSum[1]+stepScore[2];
    }
    else{
        maxSum[1]=stepScore[1];
        maxSum[2]=maxSum[1]+stepScore[2];

        for(int i=3;i<=n;i++) {
        maxSum[i] = max(maxSum[i-2] + stepScore[i], maxSum[i-3] + stepScore[i] + stepScore[i-1]);
        }
    }

    cout << maxSum[n] << "\n";

    return 0;
}