#include <cstdio>
#include <vector>
using namespace std;

int BreakEgg(vector<pair<int, int> > v, int k, int n){
	int max = -1;
	
	while(v[k].first <= 0 && k < n) k++;
	
	if(k == n){
		int count = 0;
		for(int i=0; i<v.size(); i++){
			if(v[i].first <= 0) count++;
		}
		return count;
	}
	
	int brokenEggs = 0;
	for(int i=0; i<n; i++){
		if(k == i) continue;
		if(v[i].first <= 0){
			brokenEggs++;
			continue;
		}
		
		vector<pair<int, int> > u;
		u.resize(v.size());
		copy(v.begin(), v.end(), u.begin());
		u[k].first -= u[i].second;
		u[i].first -= u[k].second;
		
		int temp = BreakEgg(u, k+1, n);
		if(temp > max) max = temp;
	}
	
	if(brokenEggs == n-1) return n-1;
	
	return max;
}

int main(){
	int n, max = -1;
	scanf("%d", &n);
	
	vector<pair<int, int> > v;
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({x, y});
	}
	
	printf("%d", BreakEgg(v, 0, n));
}
