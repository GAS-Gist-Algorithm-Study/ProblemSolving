#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[1001][1001];

int main(){
	char a[1001], b[1001];
	scanf("%s\n%s", a, b);
	
	for(int i=1; i<=strlen(a); i++){
		for(int j=1; j<=strlen(b); j++){
			if(a[i-1] == b[j-1]) DP[i][j] = 1 + DP[i-1][j-1];
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
	}
	
	for(int i=0; i<=strlen(a); i++){
		for(int j=0; j<=strlen(b); j++)
			printf("%d ", DP[i][j]);
		printf("\n");
	}
	
	printf("%d", DP[strlen(a)][strlen(b)]);
}
