#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int DP[5001][5001];

int main(){
	int n;
	scanf("%d", &n);
	char a[5001], b[5001];
	scanf("%s", a);
	int size = strlen(a);
	for(int i=0; i<size; i++)
		b[i] = a[size - i - 1];
	
	for(int i=1; i<=size; i++)
		for(int j=1; j<=size; j++){
			if(a[i-1] == b[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
			else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
		
	printf("%d", size - DP[size][size]);
}
