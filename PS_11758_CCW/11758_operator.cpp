#include<iostream>
#include<cstdio>
//pair만 쓸거만 utility, algorithm이 utility 포함, iostream도 utility 포함
using namespace std;
typedef pair<int,int> pi;

struct Point{
    pi p;
    Point operator - (const Point &A) const{
        Point B;
        B.p.first = p.first - A.p.first;
        B.p.second = p.second - A.p.second;
        return B;
    }
    int operator * (const Point &A) const{
        if(p.first * A.p.second - A.p.first * p.second > 0) return 1;
        else if(p.first * A.p.second - A.p.first * p.second < 0) return -1;
        else return 0;
    }
};

int main(){
    Point points[3];
/*
    for(int i=0;i<3;i++)
        cin >> points[i].p.first >> points[i].p.second;
*/
    for(int i=0;i<3;i++)
        scanf("%d %d",&points[i].p.first, &points[i].p.second);

    Point vector1 = points[1] - points[0];
    Point vector2 = points[2] - points[1];

    printf( "%d", vector1 * vector2 );
    //cout << vector1 * vector2;
}

//ref와 pointer의 차(&는 c++에만 있음)
//pointer는 소프트링크 ref는 하드링크
//pointer로 다른 함수에 인자로 넣어주면 주소를 넣을 곳을 만들고 그곳에 해당주소를 복사해서 넣어야함
//해당과정이 생략이 됨
//C를 언제씀? C++을 못쓸때