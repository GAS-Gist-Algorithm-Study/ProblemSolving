#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define point pair<int,int> 
#define X first
#define Y second
using namespace std;

struct needTwoStone{
    int value;
    point P1;
    point P2;
    needTwoStone(int v, point p1, point p2) : value(v), P1(p1), P2(p2){}
};

vector<point> V1;
vector<needTwoStone> V2;

void BFS(int x, int y, int ** table){
    int numberOfPoints = 1;
    vector<point> v;
    table[y][x] = 3;
    queue<point> q;
    q.emplace(x,y);
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while ( !q.empty() ){
        point p = q.front();
        q.pop();
        for ( int d = 0; d < 4; d++ ){
            int newX, newY;
            newX = p.X + dx[d];
            newY = p.Y + dy[d];
            if ( table[newY][newX] == 2 ){
                q.emplace(newX,newY);
                table[newY][newX] = 3;
                numberOfPoints++;
            }
            else if ( table[newY][newX] <= 0 && v.size() <= 2){
                bool checkDuplication = false;
                for( auto p_v : v ){
                    if ( p_v.X == newX && p_v.Y == newY )
                        checkDuplication = true;
                }
                if (!checkDuplication)
                    v.emplace_back(newX,newY);
            }
        }
    }
    if ( v.size() == 1 ){
        if(table[v[0].Y][v[0].X] ==  0)
            V1.emplace_back(v[0].X,v[0].Y);
        table[v[0].Y][v[0].X] -= numberOfPoints;
    }
    else if ( v.size() == 2 ){
        for( auto v2: V2)
            if(v2.P1 == v[0] && v2.P2 == v[1] || v2.P1 == v[1] && v2.P2 == v[0] ){
                numberOfPoints+=v2.value;
            }
        V2.emplace_back(numberOfPoints,v[0],v[1]);
    }
}

void findEnemy(int row, int column, int** table){
    for ( int y = 1; y <= column; y++){
        for ( int x = 1; x<= row; x++){
            if (table[y][x] == 2){
                BFS(x,y,table);
            }
        }
    }
}

int findSumOf2Points(int** table){
    int minFirst=0, minSecond=0;
    for(int i=0; i<V1.size(); i++){
        int value = table[V1[i].Y][V1[i].X];
        if(minSecond > value){
            if(minFirst > value){
                minSecond = minFirst;
                minFirst = value;
            }
            else{
                minSecond = value;
            }
        }
    }
    return minFirst + minSecond;
}

int findMax(int** table){
    int maxValue = -findSumOf2Points(table);
    for( auto v2: V2 ){
        maxValue = max(maxValue,v2.value-table[v2.P1.Y][v2.P1.X]-table[v2.P2.Y][v2.P2.X]);
    }
    return maxValue;
}

int main(){
    int row, column;
    cin >> column >> row;
    int** table = (int**) malloc ( sizeof(int*) * (column+2) );
    for ( int y = 0; y <= column+1; y++){
        table[y] = (int*) malloc ( sizeof(int) * (row+2) );
        for ( int x = 0; x <= row+1; x++){
            if ( x == 0 || x == row+1 || y == 0 || y == column+1 )
                table[y][x] = 1;
            else{
                cin >> table[y][x];
            }
        }
    }
    findEnemy(row, column, table);
    cout << findMax(table);
}
