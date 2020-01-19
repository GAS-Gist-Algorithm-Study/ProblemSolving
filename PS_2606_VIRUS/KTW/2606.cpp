#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
	bool visited;
	vector<node*> nexts;
	node(){
		visited = false;
	}
};

void dfs(node* n1){
	if(!n1->visited){
		n1->visited = true;
		for(auto n2 : n1->nexts){
			dfs(n2);
		}
	}
}

void bfs(node* n1){
	queue<node*> q;
	q.push(n1);
	while(!q.empty()){
		node* x= q.front();
		x->visited = true;
		q.pop();
		for(auto y : x->nexts) {
			if(!y->visited) q.push(y);	
		}	
	}
}

int main(){
	int computer, connect;
	cin >> computer >> connect;
	node* Nodes[101];
	for(int n = 1; n <= computer; n++){
		Nodes[n] = new node();
	}
	for(int i = 0; i < connect ; i++){
		int x,y;
		cin >> x >> y;
		Nodes[x]->nexts.push_back(Nodes[y]);	
		Nodes[y]->nexts.push_back(Nodes[x]);	
	}
	bfs(Nodes[1]);
	int ans = 0;
	for(int n=1; n<=computer; n++){
		if(Nodes[n]->visited) ans++;
	}
	cout << ans-1;
	return 0;
}
