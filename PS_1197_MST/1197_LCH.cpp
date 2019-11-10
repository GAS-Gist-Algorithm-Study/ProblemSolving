#include <cstdio>
#include <vector>
#include <algorithm>

#define tii pair<pair<int,int>,int>

using namespace std;

vector<tii> e;

int visited[10001];
int ans = 0;

bool compare(const tii &a, const tii &b){
	if(a.second < b.second) return true;
	return false;
}

int finding(int n){
	if(visited[n] == n) return n;
	else return finding(visited[n]);
}

int main(){
	int nv, ne;
	scanf("%d %d", &nv, &ne);
	for(int i=0; i<ne; i++){
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		e.push_back({{x,y},z});
	}
	
	for(int i=0; i<=nv; i++)
		visited[i] = i;
	
	sort(e.begin(), e.end(), compare);
	
	for(int i=0; i<e.size(); i++){
		if(finding(e[i].first.first) < finding(e[i].first.second)){
			visited[finding(e[i].first.second)] = finding(e[i].first.first);
			ans += e[i].second;
		}
		
		else if(finding(e[i].first.first) > finding(e[i].first.second)){
			visited[finding(e[i].first.first)] = finding(e[i].first.second);
			ans += e[i].second;
		}
	}
	printf("%d", ans);
}
