#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    int len1, len2;
    len1 = str1.length();
    len2 = str2.length();
    
    int dp[len1+1][len2+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else{
                if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout << dp[len1][len2] << endl;
}