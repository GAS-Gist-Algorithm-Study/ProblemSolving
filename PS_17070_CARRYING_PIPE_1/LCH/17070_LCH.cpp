#include <cstdio>
#include <cstring>

int main(){
	int n, house[32][32];
	long long int dp[3][32][32];
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &house[i][j]);
			
	memset(dp, 0, sizeof(dp));
	
	dp[0][0][1] = 1;
	
	for(int i=0; i<n; i++)
		for(int j=1; j<n; j++){
			if(!house[i][j]){
				for(int k=0; k<2; k++)
					dp[0][i][j] += dp[k][i][j-1];
				if(i != 0){
					for(int k=0; k<3; k++)
						if(!(house[i-1][j] || house[i][j-1])) dp[1][i][j] += dp[k][i-1][j-1];
					for(int k=1; k<3; k++)
						dp[2][i][j] += dp[k][i-1][j];
				}
			}
		}
	printf("%lld", dp[0][n-1][n-1] + dp[1][n-1][n-1] + dp[2][n-1][n-1]);
}
