#include <cstdio>

int main(){
	int map[50][50], temp[50][50], r, c, t, cleaner1 = -1, cleaner2;
	scanf("%d %d %d", &r, &c, &t);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == -1 && cleaner1 == -1){
				cleaner1 = i;
				cleaner2 = i + 1;
			}
		}
	
	for(int test = 0; test < t; test++){
		//init
		for(int k = 0; k < r; k++)
			for(int l = 0; l < c; l++)
				temp[k][l] = 0;
		
		temp[cleaner1][0] = -1;
		temp[cleaner2][0] = -1;
		
		//defusion
		for(int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				int mise = map[i][j];
				
				if(mise == 0 || mise == -1) continue;
				
				int ways = 4;
				
				if(i == 0 || temp[i-1][j] == -1) ways--;
				else temp[i-1][j] += mise / 5;
				
				if(i == r - 1 || temp[i+1][j] == -1) ways--;
				else temp[i+1][j] += mise / 5;
				
				if(j == 0 || temp[i][j-1] == -1) ways--;
				else temp[i][j-1] += mise / 5;
				
				if(j == c - 1) ways--;
				else temp[i][j+1] += mise / 5;
				
				temp[i][j] += mise - ((mise / 5) * ways);
			}
		}

		//cycle1
		for(int k = cleaner1; k > 0; k--){
			temp[k][0] = temp[k-1][0];
		}
		
		for(int k = 0; k < c - 1; k++){
			temp[0][k] = temp[0][k+1];
		}
		
		for(int k = 0; k < cleaner1; k++){
			temp[k][c-1] = temp[k+1][c-1];
		}
		
		for(int k = c - 1; k > 1; k--){
			temp[cleaner1][k] = temp[cleaner1][k-1];
		}
		
		temp[cleaner1][0] = -1;
		temp[cleaner1][1] = 0;
		
		//cycle2
		for(int k = cleaner2; k < r - 1; k++){
			temp[k][0] = temp[k+1][0];
		}
		
		for(int k = 0; k < c - 1; k++){
			temp[r-1][k] = temp[r-1][k+1];
		}
		
		for(int k = r - 1; k > cleaner2; k--){
			temp[k][c-1] = temp[k-1][c-1];
		}
		
		for(int k = c - 1; k > 1; k--){
			temp[cleaner2][k] = temp[cleaner2][k-1];
		}
		
		temp[cleaner2][0] = -1;
		temp[cleaner2][1] = 0;
		
		//temp to map
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				map[i][j] = temp[i][j];
	}
	
	//total dust
	int sum = 0;
	
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			sum += map[i][j];
			
	printf("%d", sum + 2);
}
