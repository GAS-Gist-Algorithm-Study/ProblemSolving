#include <cstdio>

int main(){
	int n, m, r, c, d, map[50][50];
	int dy[4] = {0, 1, 0, -1};
	int dx[4] = {-1, 0, 1, 0};
	
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);
			
	int check = 1, count = 0;
	
	while(1){
		if(map[r][c] == 0 && check) map[r][c] = 9; //step 1
		
		check = 1;
		
		if(count == 4){//step 2.c and 2.d
			if(map[r + dx[(d + 2) % 4]][c + dy[(d + 2) % 4]] != 1){ //step 2.c
				r += dx[(d + 2) % 4];
				c += dy[(d + 2) % 4];
				check = 0;
				count = 0;
				continue;
			}
			else{// step 2.d
				break;
			}
		}
		
		if(map[r + dx[(d + 3) % 4]][c + dy[(d + 3) % 4]] == 0){// step 2.a
			d = (d + 3) % 4;
			r += dx[d];
			c += dy[d];
			count = 0;
			continue;
		}
		
		if(map[r + dx[(d + 3) % 4]][c + dy[(d + 3) % 4]] == 1 || map[r + dx[(d + 3) % 4]][c + dy[(d + 3) % 4]] == 9){// step 2.b
			d = (d + 3) % 4;
			check = 0;
			count++;
			continue;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 9) ans++;
		}
	}
			
	printf("%d", ans);
}
