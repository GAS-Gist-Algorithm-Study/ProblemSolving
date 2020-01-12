#include <iostream>

using namespace std;

int N,M,K,x,y;
int map[21][21];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
int dice[6] = {0,};
//pair<int,int,int> diceIndex;
class topFrontEast{
    public:
        int top;
        int front;
        int east;
};

topFrontEast diceIndex;


void moveDice(int command);

int main(){
    int direction;
    diceIndex.top = 1;
    diceIndex.front = 2;
    diceIndex.east = 3;

    cin >> N >> M >>x>>y>> K;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M;j++){
            cin >> map[i][j];
        }
    }
    dice[5] = map[x][y];

    for (int k = 0; k<K;k++){
        cin >> direction;
        moveDice(direction);
    }

}


//원본 다이스에서
void spinDice(int command){
    int ot = diceIndex.top;
    int of = diceIndex.front;
    int oe = diceIndex.east;

    if(command == 1){
        diceIndex.top = 7-oe;
        diceIndex.east = ot;    
    }
    if(command == 2){
        diceIndex.top = oe;
        diceIndex.east = 7-ot;
    }
    if(command == 3){
        diceIndex.top = 7-of;
        diceIndex.front = ot;
    }
    if(command == 4){
        diceIndex.top = of;
        diceIndex.front = 7-ot;
    }
}



//주사위 윗면 수와 이동 방향
void moveDice(int command){

    int nx = x + dr[command-1];
    int ny = y + dc[command-1];
//   cout<<"nx: "<<nx<<"ny: "<<ny<<endl;
    if(nx>=0&&ny>=0&&nx<N&&ny<M){
        x = nx;
        y = ny;
//    cout<<"map value: "<<map[x][y]<<endl;
        spinDice(command);
        if(map[x][y]==0)
            map[x][y] = dice[6-diceIndex.top];
        else{
            dice[6-diceIndex.top] = map[x][y];
            map[x][y] = 0;}
        cout << dice[diceIndex.top-1]<<endl;
    }

    else return;
}
