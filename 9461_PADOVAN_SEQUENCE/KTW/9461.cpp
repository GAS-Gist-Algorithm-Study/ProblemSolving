#include<iostream>
using namespace std;
long long table[100];

void makeTable(){
    table[0] = 1;
    table[1] = 1;
    table[2] = 1;
    table[3] = 2;
    table[4] = 2;
    for ( int i = 5; i < 100; i ++ )
        table[i] = table[i-1] + table[i-5];
}


int main(){
    makeTable();
    int T;
    cin >> T;
    for ( int t = 0; t < T; t++ ){
        int n;
        cin >> n;
        cout << table[n-1] << "\n";
    }
        
}
