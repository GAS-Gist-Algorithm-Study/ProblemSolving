#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int start, end, score;
}road;

bool compare(const road &a, const road &b){
	if(a.end == b.end) return a.start > b.start;
	return a.end > b.end;
}

int main(){
	int n, m, k;
	vector<road> v;
	scanf("%d %d %d", &n, &m, &k);
	
	int DP[301][301];
	memset(DP, 0, sizeof(DP));
	
	for(int i=0; i<k; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(x < y) v.push_back({x, y, z});
	}
	
	sort(v.begin(), v.end(), compare);
	
	int i = 0, size = v.size();
	
	while(v[i].end == n){
		if(DP[v[i].start][1] < v[i].score) DP[v[i].start][1] = v[i].score;
		i++;
	}
	
	while(i < size){
		for(int j = 1; j < m; j++)
			if(DP[v[i].start][j+1] < DP[v[i].end][j] + v[i].score) DP[v[i].start][j+1] = DP[v[i].end][j] + v[i].score;
		i++;
	}
	
	int max = -1;
	for(int i=1; i<m; i++)
		if(max < DP[1][i]) max = DP[1][i];
	
	printf("%d", max);
}
