#include <cstdio>
#include <utility>
using namespace std;

int main(){
	pair <int,int> p[3];
	for(int i=0; i<3; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	
	pair <int,int> vec[2] = {{p[0].first - p[1].first, p[0].second - p[1].second}, {p[2].first - p[1].first, p[2].second - p[1].second}};
	if(vec[0].first * vec[1].second - vec[0].second * vec[1].first < 0) printf("1");
	else if(vec[0].first * vec[1].second - vec[0].second * vec[1].first > 0) printf("-1");
	else printf("0");
}
