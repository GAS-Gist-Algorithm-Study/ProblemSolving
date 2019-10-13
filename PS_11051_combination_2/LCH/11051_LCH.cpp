#include <cstdio>

int DP[1001][1001];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i=0; i<=n; i++){
		DP[0][i] = 0;
		DP[i][0] = 1;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			DP[j][i] = (DP[j-1][i-1] + DP[j-1][i]) % 10007;
			
	printf("%d", DP[n][k]);
}
