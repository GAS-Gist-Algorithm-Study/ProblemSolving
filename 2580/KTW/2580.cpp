#include<iostream>
#include<vector>
using namespace std;
#define point pair<int,int> 
#define x first
#define y second

bool checkHorizon(int table[][9], point p, int v){
    for ( int i = 0; i < 9; i++ )
        if ( v == table[i][p.y] )
            return false;
    return true;
}

bool checkVerical(int table[][9], point p, int v){
    for ( int i = 0; i < 9; i++ )
        if ( v == table[p.x][i] )
            return false;
    return true;
}

bool checkSquare(int table[][9], point p, int v){
    int a = 3 * ( p.x / 3 );
    int b = 3 * ( p.y / 3 );
    for ( int j = b; j < b+3; j++ )
       for ( int i = a; i < a+3; i++ )
          if ( v == table[i][j] )
             return false;
   return true; 
}

void printTable(int table[][9]){
    for ( int column = 0; column < 9; column++ ){
        for ( int row = 0; row < 9; row++ )
            cout << table[row][column] << " ";
        cout << "\n";
    }
}
vector<int> findListOfNumber(int table[][9], point p){
    vector<int> list;
    for ( int v = 1; v <= 9; v++)
        if ( checkHorizon(table, p, v) && checkVerical(table, p, v) && checkSquare(table, p, v) )
            list.emplace_back(v);
    return list;
}    
         
void solveSudoku(int table[][9], vector<point> points, int indexToShow){
    point p = points[indexToShow];
    vector<int> possibleNumber = findListOfNumber(table, p);
    for ( int& v : possibleNumber){
        table[p.x][p.y] = v;
        if ( indexToShow == points.size()-1 ){
            printTable(table);
            exit(0);
        }
        solveSudoku(table, points, indexToShow+1); 
        table[p.x][p.y] = 0;
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int table[9][9];
    vector<point> points;
    for ( int column = 0; column < 9; column++ )
        for ( int row = 0; row < 9; row++ ){
            cin >> table[row][column];
            if ( table[row][column] == 0 )
                points.emplace_back(make_pair(row,column));
        }
    solveSudoku(table, points, 0);
}
