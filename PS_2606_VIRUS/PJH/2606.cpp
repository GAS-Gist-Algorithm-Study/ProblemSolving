#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
  node() { visited = false; }
  bool visited;
  vector<node*> neighbors;
};

int DFS(node* root) {
  int cnt = 1;
  root->visited = true;

  for (node* next: root->neighbors)
    if (next->visited == false)
      cnt += DFS(next);

  return cnt;
}

int BFS(node* root) {
  int cnt = 0;
  queue<node*> q;

  q.push(root);
  root->visited = true;

  while (!q.empty()) {
    root = q.front();
    cnt++;
    q.pop();
    for (node* next: root->neighbors)
      if (next->visited == false) {
        q.push(next);
        next->visited = true;
      }
  }

  return cnt;
}

int main() {
  int N, M;
  node* nodes[101];
  
  cin >> N
      >> M;

  for (int i = 1; i <= N; i++) 
    nodes[i] = new node();
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    nodes[a]->neighbors.push_back(nodes[b]);
    nodes[b]->neighbors.push_back(nodes[a]);
  }

  //cout << DFS(nodes[1]) - 1 << endl;
  cout << BFS(nodes[1]) - 1 << endl;
  
  return 0;
}
