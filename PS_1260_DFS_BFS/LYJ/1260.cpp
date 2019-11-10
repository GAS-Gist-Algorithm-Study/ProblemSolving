#include<cstdio>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

stack<int> s1;
queue<int> q1;

int main(){
    int n,m,v;
    cin >> n >> m >> v;

    int adj[1001][1001]={0,};
    int visited[1001]={0,};

    int j,k;
    for(int i=0;i<m;i++){
        cin >> j >> k;

        adj[j][k]++;
        adj[k][j]++;
    }

    s1.push(v);
    cout << v << " ";
    while(!s1.empty()){
        int cur = s1.top(), f=1;
        visited[cur]=1;
        for(int i=1;i<n+1;i++){
            if(adj[cur][i] && visited[i]!=1){
                s1.push(i);
                cout << i << " ";
                f=0;
                break;   
            }
        }
        if(f) s1.pop();
    }

    int visited2[1001]={0,};

    q1.push(v);
    cout << "\n" << v << " ";
    while(!q1.empty()){
        int cur = q1.front();
        visited2[cur]=1;
        for(int i=1;i<n+1;i++){
            if(adj[cur][i] && visited2[i]!=1){
                q1.push(i);
                cout << i << " ";
                visited2[i]=1;
            }
        }
        q1.pop();
    }
    cout << "\n";

    return 0;
}