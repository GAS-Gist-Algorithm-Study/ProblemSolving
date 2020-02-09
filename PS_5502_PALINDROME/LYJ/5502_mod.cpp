#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[5001][5001];

int palindrome(string str1, string str2, int dp[5001][5001]){
    int len = str1.length();

    for(int i=0;i<=len;i++){
        for(int j=0;j<=len;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else{
                if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return len - dp[len][len];
}
int main(){
    int num;
    string str1;

    cin >> num >> str1;

    string str2 = str1;
    reverse(str2.begin(),str2.end());
    
    cout <<  palindrome(str1, str2, dp) << endl;
}