#include <cstdio>
#include <vector>
using namespace std;

typedef struct node{
	node() {visited = false;}
	bool visited;
	vector<node*> v;
}node;

int dfs(node* n){
	int count = 1;
	n->visited = true;
	for(int i=0; i<n->v.size(); i++)
		if(n->v[i]->visited == false)
			count += dfs(n->v[i]);
	return count;
}

int main(){
	int temp, n;
	node com[101];
	scanf("%d %d", &temp, &n);
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x ,&y);
		com[x].v.push_back(&com[y]);
		com[y].v.push_back(&com[x]);
	}
	
	printf("%d", dfs(&com[1]) - 1);
}
