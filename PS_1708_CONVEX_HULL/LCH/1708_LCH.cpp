#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

pii point[100001];

bool compare(const pii &a, const pii &b){
	if(a.first < b.first) return true;
	else if(a.first == b.first){
		if(a.second < b.second) return true;
		else return false;
	}
	else return false;
}

bool compare2(const pii &a, const pii &b){
	if(1 * a.second * b.first < 1 * b.second * a.first) return true;
	if(1 * a.second * b.first > 1 * b.second * a.first) return false;
	if(a.second < b.second) return true;
	if(a.second > b.second) return false;
	if(a.first < b.first) return true;
	return false;
}

pii operator - (const pii &a, const pii &b){
	return {a.first - b.first, a.second - b.second};
}

int ccw(pii a, pii b, pii c){
	pii ab = b - a;
	pii bc = c - b;
	return ab.first * bc.second - ab.second * bc.first;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &point[i].first, &point[i].second);
	
	sort(point, point+n, compare);
	
	for(int i=1; i<n; i++){
		point[i].first -= point[0].first;
		point[i].second -= point[0].second;
	}
	point[0] = {0,0};
	
	sort(point+1, point+n, compare2);
	
	point[n] = {0,0};
	
	stack<int> s;
	s.push(0);
	s.push(1);
	for(int i=2; i<=n; i++){
		while(1){
			if(s.size() == 1){
				s.push(i);
				break;
			}
			int second = s.top();
			s.pop();
			int first = s.top();
			if(ccw(point[first], point[second], point[i]) > 0){
				s.push(second);
				s.push(i);
				break;
			}
			if(ccw(point[first], point[second], point[i]) == 0){
				if(abs(point[first].first - point[second].first) < abs(point[first].first - point[i].first)) continue;
				else break;
			}
		}
	}
	printf("%d", s.size()-1);
}
