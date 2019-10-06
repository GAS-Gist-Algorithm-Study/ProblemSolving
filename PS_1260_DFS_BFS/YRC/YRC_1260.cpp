#include <iostream>
#include <queue>

using namespace std;

int N,M,V;
bool adj[1001][1001];
bool visited[1001];



void DFS(int root){
  cout << root << " ";
  visited[root] = true;

  for(int i=0;i<N+1;i++){
    if(adj[root][i]&&!visited[i])
      DFS(i);
  }
}
void BFS(int root){
  queue<int> order;

  if(!visited[root]){
    order.push(root);
    visited[root] = true;
  }

  while(!order.empty()){
    root = order.front();
    for(int i=0;i<N+1;i++){
      if(adj[root][i]&&!visited[i]){
        order.push(i);
        visited[i] = true;
      }
    }
    cout << order.front() << " ";
    order.pop();
  }
}

int main (){
  cin >> N >> M >> V;
  int a,b;
  for(int i=0;i<M;i++){
    cin >> a>>b;
    adj[a][b] = adj[b][a] = true;
  }

  DFS(V);

  for(int i =0;i<N+1;i++){
    visited[i] = false;
  }

  cout << endl;
  BFS(V);

}
