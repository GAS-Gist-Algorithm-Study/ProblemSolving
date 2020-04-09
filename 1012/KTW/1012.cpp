#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void DFS(int i, int j, const int& M, const int& N, bool (&field)[50][50]){
    for (int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        if (x >= 0 && y >= 0 && x < M && y < N && field[x][y]){
            field[x][y] = false;
            DFS(x, y, M, N, field);
        }
    }
}

int findNumberOfBug(const int& M, const int& N, bool (&field)[50][50]){
    int numberOfBugs = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            if (field[i][j]){
                DFS(i, j, M, N, field);
                numberOfBugs++;
            }
    return numberOfBugs;
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    bool field[50][50] = {false};

    int testCase;
    cin >> testCase;
    for (int Case = 0; Case < testCase; Case++){
        int M, N, K;
        cin >> M >> N >> K;
        for (int k = 0; k < K; k++){
            int x,y;
            cin >> x >> y;
            field[x][y] = true;
        }
        cout << findNumberOfBug(M,N,field) << '\n';
        memset(field, 0, sizeof(field));
    }
    return 0;
}
