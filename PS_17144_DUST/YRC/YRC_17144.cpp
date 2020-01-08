#include <iostream>
#include <vector>

using namespace std;

int R,C,T,conditioner;
int dust[51][51];
int dustcopy[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void SpreadDust();
void Cleaning();
int CountDust();


int main (){
    cin >> R >> C >> T;
    for (int i = 0;i<R;i++){
        for (int j = 0; j<C;j++){
            cin >> dust[i][j];
            if (dust[i][j]==-1)
                conditioner = i;
        }
    }
    conditioner--;

    for (int t = 0; t<T;t++){
        SpreadDust();
        Cleaning();
    }
    cout << CountDust();
}

void SpreadDust(){
    int temp[51][51] = {0,};
    int x,y;
    for (int i = 0; i<R;i++){
        for (int j = 0; j<C;j++){
            int count = 0;
            for (int k = 0; k<4;k++){
                x = i + dx[k];
                y = j + dy[k];
                

                if(x>=0 && x<R && y>=0 && y<C && dust[x][y]!=-1){
                    count ++;
                    temp[x][y] += dust[i][j]/5;
                }   
            }
        dust[i][j] -= (dust[i][j]/5)*count;
        }
    }
    for (int i = 0; i<R;i++){
        for (int j = 0;j<C;j++){
            dust[i][j] += temp[i][j];
            dustcopy[i][j] = dust[i][j];
        }
    }
}

void Cleaning(){
    for (int i = conditioner+2 ; i< R-1;i++){
        dust[i][0] = dustcopy[i+1][0];
        dust[i][C-1] = dustcopy[i-1][C-1];
    }

    for (int i = 1; i<conditioner;i++){
        dust[i][0] = dustcopy[i-1][0]; 
        dust[i][C-1] = dustcopy[i+1][C-1];  
    }

    for (int j = 0; j<C-1;j++){
        dust[0][j] = dustcopy[0][j+1];
        dust[R-1][j] = dustcopy[R-1][j+1];
    }

    for (int j = 2;j<C;j++){
        dust[conditioner][j] = dustcopy[conditioner][j-1]; 
        dust[conditioner+1][j] = dustcopy[conditioner+1][j-1];
    }

    dust[conditioner][1] = 0;
    dust[conditioner+1][1] = 0;
    dust[0][C-1] = dustcopy[1][C-1];
    dust[R-1][C-1] = dustcopy[R-2][C-1];

}
int CountDust(){
    int sum = 2;
    for (int i = 0; i< R ; i++){
        for (int j = 0; j<C; j++){
            sum += dust[i][j];
        }
    }
    return sum;
}