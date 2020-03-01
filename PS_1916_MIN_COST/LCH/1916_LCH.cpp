#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int dest, w;
}edge;

bool compare(const edge &a, const edge &b){
	return a.dest < b.dest;
}

int main(){
	int n, m, x, y, w, city[1001];
	scanf("%d %d", &n, &m);
	vector<edge> v[1001];
	for(int i=1; i<=n; i++)
		city[i] = 2147483647;
	
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &x, &y, &w);
		v[x].push_back({y, w});
	}
	for(int i=1; i<=n; i++)
		sort(v[i].begin(), v[i].end(), compare);
	
	scanf("%d %d", &x, &y);
	city[x] = 0;
	
	stack<int> s;
	s.push(x);
	//dfs
	while(!s.empty()){
		int top = s.top();
		s.pop();
		for(int i=0; i<v[top].size(); i++){
			if(city[top] + v[top][i].w < city[v[top][i].dest]){
				s.push(v[top][i].dest);
				city[v[top][i].dest] = city[top] + v[top][i].w;
			}
		}
	}
	
	printf("%d", city[y]);
}
