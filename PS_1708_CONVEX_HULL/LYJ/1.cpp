#include<iostream>
 #include<vector>
 #include<algorithm>

 using namespace std;

 class Point{
     public:
     long long x;
     long long y;

     Point(long long x=0, long long y=0) : x(x), y(y) { }

     bool operator <(const Point& A)const{
         if(A.x == x) return (y < A.y);
         else if(x < A.x) return true;
         else return false;
     }

     Point operator - (const Point& A)const{
         return Point(x-A.x, y-A.y);
     }
 };

 int CCW(Point ab, Point bc){
     if(ab.x * bc.y - ab.y * bc.x > 0) return 1;
     else if(ab.x * bc.y - ab.y * bc.x < 0) return -1;
     else return 0;
 }

 int CCW(Point a, Point b, Point c){
     return CCW(b-a, c-b);
 }

 int main(){
     int num;
     cin >> num;
     vector<Point> points;
     Point temp;

     for(int i=0;i<num;i++){
         cin >> temp.x >> temp.y;
         points.emplace_back(temp);
     }
     sort(points.begin(), points.end());

     Point startPoint = points[0];
     stable_sort(points.begin(), points.end(), [&startPoint](Point a, Point b){
         Point ma = a - startPoint;
         Point mb = b - startPoint;
         return ma.y * mb.x < mb.y * ma.x;
     });

    points.emplace_back(startPoint);
     vector<Point> convexHull;

     convexHull.emplace_back(points[0]);
     convexHull.emplace_back(points[1]);

     int target = 2;

     while(target <= num){
         if(CCW(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1]
         , points[target]) > 0){
             convexHull.emplace_back(points[target++]);
         }
         else{
             if(convexHull.size() > 1)
                convexHull.pop_back();
         }
     }


     cout << convexHull.size()-1 << endl;

 } 