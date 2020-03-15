#include <cstdio>
#include <cstring>

void dfs(int x, int y, int field[50][50], int n, int m, int count){
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	if(field[x][y] == -1){
		field[x][y] = count;
		for(int i=0; i<4; i++)
			if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m){
				dfs(x + dx[i], y + dy[i], field, n, m, count);
			}
	}
}

int main(){
	int field[50][50], T;
	scanf("%d", &T);
	
	for(int testcase=0; testcase<T; testcase++){
		
		memset(field, 0, sizeof(field));
		
		int n, m, k, count = 1;
		scanf("%d %d %d", &n, &m, &k);
		
		for(int i=0; i<k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			field[x][y] = -1;
		}
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				if(field[i][j] == -1){
					dfs(i, j, field, n, m, count);
					count++;
				}
			}
		
		printf("%d\n", count - 1);
	}
}
