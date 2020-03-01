#include<iostream>
using namespace std;

int CCW(int points[3][2]){
    if((points[1][0] - points[0][0]) * (points[2][1] - points[1][1]) 
    - (points[1][1] - points[0][1]) * (points[2][0] - points[1][0])>0) return 1;
    else if((points[1][0] - points[0][0]) * (points[2][1] - points[1][1]) 
    - (points[1][1] - points[0][1]) * (points[2][0] - points[1][0])<0) return -1;
    else return 0;
}

int main(){
    int points[3][2];
    
    for(int i=0;i<3;i++)
        cin >> points[i][0] >> points[i][1];
    
    cout << CCW(points);
}