#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int R=0,G=0,B=0;
    int N;
    cin >> N;
    for ( int i = 0; i < N; i++ ){
        int r,g,b,R0,G0,B0;
        cin >> r >> g >> b;
        R0 = R;
        G0 = G;
        B0 = B;
        R = min(G0+r,B0+r);
        G = min(R0+g,B0+g);
        B = min(R0+b,G0+b);
    }
    cout << min(R, min(G,B));
}
