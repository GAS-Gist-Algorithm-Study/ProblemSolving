#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct Point{
    long long x,y;
    // Point(long long a, long long b) : x(a), y(b) {}

    Point operator-(const Point &A) const{
        return {x-A.x,y-A.y};
    }
};

bool comparePoint(Point p1, Point p2){
    if(p1.x==p2.x) return (p1.y < p2.y);
    return (p1.x < p2.x);
}

// ruturn{( x==a.x ) ? y < a.y : x < a.x; trhee hang 

bool compareSlope(Point p1, Point p2){
    if(p1.y*p2.x==p1.x*p2.y) return (p1.x < p2.x);
    return ( p1.y*p2.x < p1.x*p2.y );
}

long long CCW(Point a, Point b, Point c){
    Point ab = b-a;
    Point bc = c-b;
    return ab.x*bc.y - ab.y*bc.x;
}

int main(void){
    int N;
    cin >> N;
   
    vector<Point> points;
    for(int i=0;i<N;i++){
        Point p;
        cin >> p.x >> p.y;
        points.emplace_back(p);
    }
    sort(points.begin(),points.end(),comparePoint);
    
    bool ultimate_slope = false;
    Point ultimate_point;
    Point origin; origin.x=0; origin.y=0;
    vector<Point> origin_points;

    for(int j=1;j<N;j++){
        Point tmp;
        tmp.x = points[j].x - points[0].x;
        tmp.y = points[j].y - points[0].y;
        if(tmp.x==0){
            ultimate_slope = true;
            ultimate_point = tmp;
            continue;
        }
        origin_points.emplace_back(tmp);
    }
    sort(origin_points.begin(),origin_points.end(),compareSlope);
    
    if(ultimate_slope)
        origin_points.emplace_back(ultimate_point);
    origin_points.emplace_back(origin);

    stack<Point> st_points;
    st_points.emplace(origin);
    st_points.emplace(origin_points[0]);
    int k = 1;

    while( k < origin_points.size() ){
        Point a,b,c;
        b = st_points.top();
        st_points.pop();
        a = st_points.top();
        c = origin_points[k];
       
        if( CCW(a,b,c) == 0 ) {
            st_points.emplace(c);
            k++;
        }
       
        else if(CCW(a,b,c) > 0){
            st_points.emplace(b);
            st_points.emplace(c);
            k++;
        }
    }
     
    cout << st_points.size()-1 << endl;
    while(!st_points.empty()){
        Point p = st_points.top();
        st_points.pop();
        // cout << p.x << " " << p.y << endl;
    }
}
