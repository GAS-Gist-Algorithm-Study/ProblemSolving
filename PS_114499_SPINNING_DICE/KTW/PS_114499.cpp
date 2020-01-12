#include<iostream>
using namespace std;
int N,M,K;
int x,y;
int map[20][20];
int order[1000];
int dice[6] = {0,};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int moving_index[4][6] = {{3,1,0,5,4,2},{2,1,5,0,4,3},{4,0,2,3,5,1},{1,5,2,3,0,4}};

void moving(int dir);
bool checkValid(int dir);

int main(){
	cin >> N >> M >> x >> y >> K;
	for(int i=0; i<N ; i++){
		for(int j=0; j<M; j++){
			cin >> map[j][i];
		}
	}
	dice[6] = map[x][y];
	for(int k=0; k<K ; k++){
		int n;
		cin >> n;
		int dir = n-1;
		if(checkValid(dir)){
			moving(dir);
			cout << dice[0] << endl;
		}	
	}
	return 0;
}

void moving(int dir){
	int temp[6];
	for(int i=0; i<6; i++){
		temp[moving_index[dir][i]] = dice[i];
	}
	x = x+dx[dir];
	y = y+dy[dir];
	if(map[x][y]==0) {
		map[x][y] == temp[5];
	}
	else {
		temp[5] = map[x][y];
		map[x][y] = 0;
	}
	for (int j=0; j<6; j++){
		dice[j] = temp[j];
	}
}
bool checkValid(int dir){
	if( 0 <= x+dx[dir] && x+dx[dir] < M && 0 <= y+dy[dir] && y+dy[dir] < N) {
		return true;
	}
	return false;
}
