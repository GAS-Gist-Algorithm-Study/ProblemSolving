#include<iostream>
using namespace std;
int cache[1000001];

//재귀함수 stack이 너무 길어져서 segmentation error
int findNumberOfTile(int n){
    if ( cache[n] )
        return cache[n];
    return cache[n] = ((findNumberOfTile(n-2) + findNumberOfTile(n-1)) % 15746);
}

int findNum(int n){
    int i = 3;
    while( i <= n ){
        cache[i] = (cache[i-1]+cache[i-2]) % 15746;
        i++;
    }
    return cache[n];
}

int main(){
    int N;
    cin >> N;
    cache[1] = 1;
    cache[2] = 2;
    cout << findNum(N);
}
