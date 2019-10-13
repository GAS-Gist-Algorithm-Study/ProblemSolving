#include <cstdio>
#include <algorithm>
using namespace std;

int dp[301][2];

int main(){
	int n, a[301]; 
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	dp[0][0] = a[0];
	if(n > 1){
		dp[1][1] = a[0] + a[1];
		dp[1][0] = a[1];
	}
	
	for(int i=2; i<n; i++){
		dp[i][0] = a[i] + max(dp[i-2][0], dp[i-2][1]);
		dp[i][1] = a[i] + max(dp[i-1][0], max(dp[i-2][0], dp[i-2][1]));
	}
	
	printf("%d", max(dp[n-1][0], dp[n-1][1]));
}
