#include<iostream>
#include<vector>
using namespace std;

int dp[10001][3];

int findMaxWine(vector<int> wines, int N){
    for ( int i = 1; i <= N +1; i++ ){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1] = dp[i-1][0] + wines[i];
        dp[i][2] = dp[i-1][1] + wines[i];
    }
    return max(dp[N][0],max(dp[N][1], dp[N][2]));
}

int main(){
    int N;
    cin >> N;
    vector<int> wines;
    wines.resize(N+1);
    for ( int i = 1; i <= N; i++ )
        cin >> wines[i];
    cout << findMaxWine(wines, N);
}
