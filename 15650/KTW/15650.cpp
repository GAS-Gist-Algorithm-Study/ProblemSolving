#include<iostream>
#include<vector>
using namespace std;

void findSequence(vector<int> v, bool visited[], int top, int N, int M){
    if( v.size() == M ){
        for ( int& i : v)
            cout << i << " ";
        cout << "\n";
    }

    for ( int i = top == 0 ? 1 : v[v.size()-1] + 1; i <= N; i++ ){
        if ( !visited[i] ){
            v.emplace_back(i);
            visited[i] = true;
            findSequence(v, visited, i, N, M);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    bool visited[N+1] = {0,};
    vector<int> v;
    findSequence(v, visited, 0, N , M);
}

