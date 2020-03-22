#include<iostream>
#include<vector>
using namespace std;

void printSequence(vector<int> v, int index, vector<int> retV, int end){
    retV.emplace_back(v[index]);
    if ( v.size() == end ){
        for ( int& ret : retV )
            cout << ret << " ";
        cout << "\n";
        return;
    }
    v.erase(v.begin()+index);
    for ( int i = 0; i < v.size(); i++ )
        printSequence(v,i,retV,end);
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<int> v;
    v.resize(N);
    vector<int> retV;
    retV.reserve(M);
    for ( int i = 1; i <= N; i++ )
        v[i-1] =i;
    for (int i = 0; i < N; i++ )
        printSequence(v,i,retV,N-M+1);
}
