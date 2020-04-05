#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int table[27][27];

int DFS(int i, int j){
    if (!table[i][j])
        return 0;
    table[i][j] = 0;
    int ret = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for ( int d = 0; d < 4; d++ )
        if ( table[i+dx[d]][j+dy[d]] )
            ret += DFS(i+dx[d],j+dy[d]);
    return ret + 1;
}

void attachNumber(vector<int>& v, int N){
    for ( int j = 1; j <= N; j++ )
       for (int i = 1; i <= N; i++ )
          if (table[i][j] == 1)
             v.emplace_back(DFS(i,j)); 
}

int main(){
    int N;
    cin >> N;
    for ( int j = 1; j <= N; j++ ){
        string str;
        cin >> str;
        for ( int i = 0; i < N; i++)
            table[i+1][j] = str[i] -'0';
    }    
    vector<int> v;

    attachNumber(v, N);
    
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for ( int& n : v )
        cout << n << '\n';
    return 0;
}
