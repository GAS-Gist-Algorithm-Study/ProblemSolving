#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

pii operator -(const pii &a, const pii &b) {
	return {a.first - b.first, a.second - b.second};
}

int ccw(pii a, pii b){
	return a.first * b.second - a.second * b.first;
}

int ccw(pii a, pii b, pii c){
	return ccw(b - a, c - a);
}

int main(){
	pii p[3];
	for(int i=0; i<3; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	
	int ans = ccw(p[0], p[1], p[2]);
	if(ans > 0) printf("1");
	else if(ans < 0) printf("-1");
	else printf("0");
}
