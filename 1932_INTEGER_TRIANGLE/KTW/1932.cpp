#include<iostream>
using namespace std;
int table[501];
int copiedTable[501];

int findMax(int n){
    int maxValue = 0;
    for ( int i = 1; i <= n; i++ )
        maxValue = maxValue > table[i] ? maxValue : table[i];
    return maxValue;
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    for ( int size = 1; size <= n; size++){
        
        for ( int i = 1; i <= size; i++ )
            copiedTable[i] = table[i];
        
        for ( int i = 1; i <= size; i++ ){
            int value;
            cin >> value;
            if ( i == 1 )
                table[i] = copiedTable[i] + value;
            if ( i == size )
                table[i] = copiedTable[i-1] + value;
            else
                table[i] = max(copiedTable[i-1],copiedTable[i]) + value;
        }
    }
    cout << findMax(n);
}
