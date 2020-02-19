#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int LCS(int i, int j, string& str1, string& str2, int** dp){
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(str1[i-1]==str2[j-1])
        return dp[i][j] = LCS(i-1, j-1, str1, str2, dp) + 1;
    else
        return dp[i][j] = max(LCS(i, j-1, str1, str2, dp), LCS(i-1, j, str1, str2, dp));
}

int returnLCSLength(string& str1, string& str2){
    int len = str1.length();

    int **dp = (int**)malloc(sizeof(int *) * (len+1));

    for(int i=0;i<=len;i++)
        dp[i] = (int*)malloc(sizeof(int) * (len+1));

    for(int i=0;i<=len;i++)
        for(int j=0;j<=len;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else dp[i][j]=-1;
        }

    return LCS(len, len, str1, str2, dp);
}

int main(){
    int num;
    string str1;

    cin >> num >> str1;

    string str2 = str1;
    reverse(str2.begin(),str2.end());
    
    cout <<  str1.length() - returnLCSLength(str1, str2) << endl;
}