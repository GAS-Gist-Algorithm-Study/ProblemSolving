#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int N, map[33][33];
    cin >> N;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> map[i][j];

    long long int dp[3][33][33];
    memset(dp, 0, sizeof(long long int)*3*33*33);
    dp[0][1][2]=1;

    for(int i=3;i<=N;i++){
        if(!map[1][i]) dp[0][1][i]=dp[0][1][i-1];
        else break;
    }

    for(int i=2;i<=N;i++)
        for(int j=3;j<=N;j++){
            if(!map[i][j]){
                dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
                dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
            }
            if(!map[i][j] && !map[i-1][j] && !map[i][j-1]){
                dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
            }
        }

    
    cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N] << endl;
    return 0;
}