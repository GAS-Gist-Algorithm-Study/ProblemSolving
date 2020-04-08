#include <iostream>
#include <queue>
#define point pair<int,int>
using namespace std;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};

void BFS(const int& M, const int& N, int (&table)[100][100]){
    int ret = 0;
    queue<point> sp;
    sp.emplace(0,0);
    while(!sp.empty()){
        point p = sp.front();
        sp.pop();
        for (int d = 0; d < 4; d++){
            int x = p.first + dx[d];
            int y = p.second + dy[d];
            if ( x >= 0 && x < M && y >= 0 && y < N && table[y][x] == 1 && (x | y)){
                table[y][x] = table[p.second][p.first] + 1;
                sp.emplace(x,y);
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    
    int table[100][100] = {0,};
    for (int y = 0; y < N; y++){
        string str;
        cin >> str;
        for (int x = 0; x < M; x++)
            table[y][x] = str[x] - '0';
    }
    BFS(M, N, table);
    cout << table[N-1][M-1];
    return 0;
}
