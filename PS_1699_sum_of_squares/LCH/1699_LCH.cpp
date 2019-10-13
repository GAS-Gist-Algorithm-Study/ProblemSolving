#include <cstdio>
#include <algorithm>
using namespace std;

int DP[100001];
int main(){
	int n;
	scanf("%d", &n);

	DP[0] = 0;
		
	for(int i=1; i<=n; i++){
		DP[i] = 999999;
		int temp = 1;
		while(temp * temp <= i){
			DP[i] = min(DP[i], DP[i - temp*temp] + 1);
			temp++;
		}
	}
	
	printf("%d", DP[n]);
}
