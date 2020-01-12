#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N,M,x,y,K;
int map[20][20];
int command[1000];
int dice[6];
int temp[6];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int newx,newy;

void chDice(int);
void cpDice(int,int);
void prDice();
bool insideMap(int,int);

int main(){
    cin >> N >> M >> x >> y >> K;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }

    for(int i=0;i<K;i++)
        cin >> command[i];
    
    for(int i=0;i<K;i++){
        newx=x+dx[command[i]-1];
        newy=y+dy[command[i]-1];

        if(insideMap(newx,newy)){
            chDice(command[i]);
            cpDice(newx,newy);
            prDice();
            x=newx;
            y=newy;
        }
    }
    return 0;
}

bool insideMap(int newx,int newy){
    if(0<=newx && newx<N && 0<=newy && newy<M) return true;
    else return false;
}

void chDice(int i){
    memcpy(temp,dice,sizeof(int)*6);

    if(i==1){
        dice[0]=temp[3];
        dice[2]=temp[0];
        dice[3]=temp[5];
        dice[5]=temp[2];
    }
    else if(i==2){
        dice[0]=temp[2];
        dice[2]=temp[5];
        dice[3]=temp[0];
        dice[5]=temp[3];
    }
    else if(i==3){
        dice[0]=temp[4];
        dice[1]=temp[0];
        dice[4]=temp[5];
        dice[5]=temp[1];
    }
    else if(i==4){
        dice[0]=temp[1];
        dice[1]=temp[5];
        dice[4]=temp[0];
        dice[5]=temp[4];
    }
}
void cpDice(int newx,int newy){
    if(map[newx][newy]==0){
        map[newx][newy]=dice[5];
    }
    else{
        dice[5]=map[newx][newy];
        map[newx][newy]=0;
    }
}
void prDice(){
    cout << dice[0] << endl;
}