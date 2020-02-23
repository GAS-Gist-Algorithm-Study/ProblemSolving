#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct asdf{
	int x, y;
} pii;

pii point[100001];

pii operator -(const pii &a, const pii &b){
	pii c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

long long ccw(pii a, pii b, pii c){
	pii ab = b - a;    
	pii bc = c - b;
	return ab.x * bc.y - ab.y * bc.x;
}

bool compare(const pii &a, const pii &b){
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

bool compare2(const pii &a, const pii &b){
	if(a.x == 0){
		if(b.x == 0) return a.y > b.y;
		else return false;
	}
	if(b.x == 0) return true;
	return 1LL * a.y * b.x == 1LL * a.x * b.y ?
	a.x < b.x : 1LL * a.y * b.x < 1LL * a.x * b.y;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &point[i].x, &point[i].y);
	
	sort(point, point+n, compare);
	
	for(int i=1; i<n; i++){
		point[i].x -= point[0].x;
		point[i].y -= point[0].y;
	}
	point[0].x = point[0].y = 0;
	
	sort(point+1, point+n, compare2);
	
	point[n].x = point[n].y = 0;
	n++;
	
	stack<int> s;
	s.push(0);
	s.push(1);
	
	for(int i=2; i<n; i++){
		while(s.size() > 1){
			int second = s.top();
			s.pop();
			int first = s.top();
			if(ccw(point[first], point[second], point[i]) > 0){
				s.push(second);
				break;
			}
		}
		s.push(i);
	}
	
	printf("%d", s.size()-1);
}
