#include <iostream>

using namespace std;

class Point{
public:
    int x, y;
    Point operator -(const Point& P) const {
        Point point;
        point.x = x-P.x;
        point.y = y-P.y;
        return point;
    }
    // 벡터 외적 의미 = CCW
    int operator *(const Point& P) const {
        return x*(P.y) - y*(P.x);
    }
};

int CCW(const Point& p1, const Point& p2, const Point& p3){
    return (p2-p1)*(p3-p2);
}

int main (){
    Point p1, p2, p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;

    if(CCW(p1,p2,p3)==0)
        cout  << "0";
    else if (CCW(p1,p2,p3)>0)
        cout << "1";
    else cout << "-1";

}