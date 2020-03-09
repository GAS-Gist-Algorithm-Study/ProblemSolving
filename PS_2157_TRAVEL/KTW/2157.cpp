#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define src first
#define point second
#define edge pair<int,int>
#define imp -2
#define non_visit -1

int travel(int** lookup, const vector<edge> edges[], int N, int M){
    if ( lookup[N][M] != non_visit )
        return lookup[N][M];
    int max_point = 0;
    for ( const edge& e: edges[N] ){
        int tmp = travel(lookup,edges,e.src,(M-1));
        if ( tmp == imp )
            continue;
        if ( e.point + tmp > max_point )
            max_point = e.point + tmp;
    }
    if ( max_point == 0 )
        return lookup[N][M] = imp;
    return lookup[N][M] = max_point;
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<edge> edges[N+1];
    for ( int i = 0; i < K; i++ ){
        int a, b, c;
        cin >> a >> b >> c;
        if ( a < b )
            edges[b].emplace_back(a,c);
    }
    int** lookup = (int**)malloc((N+1) * sizeof(int*));
    for ( int j = 0; j <= N ; j++ ){
        lookup[j] = (int*)malloc((M+1) * sizeof(int));
        memset(lookup[j],-1,(M+1)*sizeof(int));
    }
    for ( int i = 1; i <= M; i++)
        lookup[1][i] = 0;
    for ( int i = 1; i <= N; i++ )
        lookup[i][0] = imp;
    cout << travel(lookup, edges, N, M) << "\n";
}
