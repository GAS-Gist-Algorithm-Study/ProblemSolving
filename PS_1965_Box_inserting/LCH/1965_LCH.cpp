#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
	int n, a[1001];
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	v.push_back(a[0]);
	
	for(int i=1; i<n; i++){
		if(v.back() < a[i])
			v.push_back(a[i]);
		else{
			vector<int>::iterator k = lower_bound(v.begin(), v.end(), a[i]);
			*k = a[i];
		}
	}
	
	printf("%d",v.size());
}
