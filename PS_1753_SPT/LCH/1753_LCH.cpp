#include <cstdio>
#include <vector>
#include <queue>
//pair<int, int> {dist, nodeID};
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
	return a.first < b.first;
}

int main(){
	int n, m, x, y, w, start, city[20001];
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++)
		city[i] = 2147483647;
	
	scanf("%d", &start);
	
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &x, &y, &w);
		v[x].push_back({w, y});
	}
	
	city[start] = 0;
	
	priority_queue<pair<int, int> > pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		pair<int, int> top = pq.top();
		pq.pop();
		int size = v[top.second].size(), t = top.second;
		for(int i=0; i<size; i++){
			if(city[t] + v[t][i].first < city[v[t][i].second]){
				city[v[t][i].second] = city[t] + v[t][i].first;
				pq.push({v[t][i].second, city[v[t][i].second]});
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		if(city[i] == 2147483647) printf("INF\n");
		else printf("%d\n", city[i]);
	}
}
