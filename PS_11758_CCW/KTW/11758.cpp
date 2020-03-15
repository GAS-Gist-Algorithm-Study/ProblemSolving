#include<iostream>
using namespace std;

struct Point{
	int x,y;
	Point operator-(const Point &A) const{
		return {x-A.x,y-A.y};
	}
};

int CCW(Point a, Point b, Point c){
	Point ab = b-a;
	Point bc = c-b;
	return ab.x*bc.y - ab.y*bc.x;
}

int main(){
	Point A[3];
	for(int i = 0; i<3; i++){
		cin >> A[i].x;
		cin >> A[i].y;
	}
	int ans = CCW(A[0],A[1],A[2]);
	if(ans > 0) cout << "1";
	else if(ans == 0) cout << "0";
	else cout << "-1";
	return 0;
}
//pointer vs reference
