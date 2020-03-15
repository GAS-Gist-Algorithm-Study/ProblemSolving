#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node{
	int depth;
	bool visited = false;
	vector<int> childs;
};

Node tree[100001];
int treemap[100001][18];

void calcDepth(int now, int depth){
	tree[now].depth = depth;
	tree[now].visited = true;

	for(int child: tree[now].childs){
		if(!tree[child].visited)
		calcDepth(child, depth+1);
	}
}

void buildTreemap(int N){
	for(int i = 0; i<N; i++){
		for(int j = 1; j < 18; j++){
			treemap[i][j] = treemap[treemap[i][j-1]][j-1]
		}
	}
}

int commonParent(int a, int b){
	tree[]

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i = 0; i< N; i++){
		int a, b;
		cin >> a>> b;
		tree[a].chlids.push_back(b);
	}

	calcDepth(1,0);
}