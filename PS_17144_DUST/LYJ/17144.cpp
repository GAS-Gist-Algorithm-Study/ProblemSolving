#include<iostream>
#include <cstring>

using namespace std;

void diffuseDust();
void cleanDust();
int sumDust();
bool insideSpace(int,int);

int map[50][50];
int mapCopy[50][50];
int cleanerP;
int R,C,T;

int main(){
    cin >> R >> C >> T;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> map[i][j];
            if(map[i][j] == -1) cleanerP=i;
        }
    }

    while(T--){
        diffuseDust();
        cleanDust();
    }

    cout << sumDust() << endl;
    return 0;
}

int sumDust(){
    int sum=0;

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            sum+=map[i][j];
    
    sum+=2;

    return sum;
}

bool insideSpace(int i, int j) {
  return i >= 0 && i < R && j >= 0 && j < C;
}

void diffuseDust(){
    int coffR[4] = { -1, 1, 0, 0 };
    int coffC[4] = { 0, 0, -1, 1};

    memset(mapCopy, 0, sizeof(int)*50*50);
    mapCopy[cleanerP-1][0]=-1;
    mapCopy[cleanerP][0]=-1;

    int con, dCon;
    int cntDiff;
    int newR, newC;

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            con=map[i][j];
            dCon=con/5;
            cntDiff=0;
            if(con==-1 || con==0) continue;

            for(int k=0;k<4;k++){
                newR=i+coffR[k];
                newC=j+coffC[k];

                if(!insideSpace(newR,newC) || map[newR][newC]==-1) continue;

                mapCopy[newR][newC]+=dCon;
                cntDiff++;
            }
            mapCopy[i][j]+=con-dCon*cntDiff;
        }
    memcpy(map,mapCopy,sizeof(int)*50*50);
}

void cleanDust(){
    map[cleanerP-1][1]=0;
    for(int j=2;j<C;j++)
        map[cleanerP-1][j]=mapCopy[cleanerP-1][j-1];
    
    for(int i=cleanerP-2;0<=i;i--)
        map[i][C-1]=mapCopy[i+1][C-1];
    
    for(int j=C-2;j>=0;j--)
        map[0][j]=mapCopy[0][j+1];
    
    for(int i=1;i<cleanerP-1;i++)
        map[i][0]=mapCopy[i-1][0];

    map[cleanerP][1]=0;
    for(int j=2;j<C;j++)
        map[cleanerP][j]=mapCopy[cleanerP][j-1];
    
    for(int i=cleanerP+1;i<R;i++)
        map[i][C-1]=mapCopy[i-1][C-1];
    
    for(int j=C-2;j>=0;j--)
        map[R-1][j]=mapCopy[R-1][j+1];

    for(int i=R-2;i>cleanerP;i--)
        map[i][0]=mapCopy[i+1][0];
}