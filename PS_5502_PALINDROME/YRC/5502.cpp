#include <iostream>
#include <cstring>
#include <vector>
#define MAX 5001

using namespace std;
int LCS[MAX][MAX];

void dp(const vector<char> &str1, const vector<char> &str2){
    int len1 = str1.size();
    int len2 = str2.size();
    for(int i = 0; i<=len1; i++){
        for(int j = 0; j<=len2; j++){
            if(i==0 || j==0) LCS[i][j] = 0;
            else{
                if(str1[i-1]==str2[j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
                else LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
}

int main(){
    int N;
    int count = 0;
    char c;
    cin >> N;
    vector<char> str;
    vector<char> revstr;

    for(int i = 0; i< N; i++){
        cin >> c;
        str.push_back(c);
    }

    for(int i = 0; i< N; i++){
        revstr.push_back(str[N-i-1]);
    }

    dp(str,revstr);
    cout << N-LCS[N][N];
}