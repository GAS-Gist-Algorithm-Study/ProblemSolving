# include <iostream>
# include <vector>
# include <algorithm>
# include <stack>
# include <cmath>
# define PI 3.14

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

class Point{
public:
    long long x, y;
    double angle;
    void setpoint(long long nx, long long ny){
        x = nx;
        y = ny;
    }
    void setAtan(double atan){
        angle = atan;
    }
};

bool comp (const Point& p1, const Point& p2){
    if (p1.angle < p2.angle) return false;
    else if (p1.angle == p2.angle){
        if(p1.x == p2.x)
            return p1.y > p2.y;
        else return p1.x > p2.x;
    }
    else return true;
}

// Calculate arctan from origin
double calcAtan(const Point& point){
    if(point.x == 0){
        if(point.y==0)
            return PI/2 +1; // 최댓값을 리턴하게함
        else if(point.y<0)
            return PI/2;
        else return -PI/2;
    }
    else return atan((double)point.y/point.x);
}

double CCW(Point& start, Point& end, Point& np){
    double v1_x = end.x - start.x;
    double v1_y = end.y - start.y;
    double v2_x = np.x - end.x;
    double v2_y = np.y - end.y;

    return ((v1_x*v2_y)-(v1_y*v2_x));
}

int main (){
    int N;
    cin >> N;
    stack <int> shell1;
    stack <int> shell2;
    int max_x_id;
    long long max_x= -40001;
    long long m_y;
    int count = 2;
    int count_on = 0;
    vector<Point> points;
    
    for (int i = 0; i< N; i++){
        Point point;
        int a, b;
        cin >> a >> b;
        point.setpoint(a,b);
        if(a>=max_x){
            max_x_id = i;
            max_x = a;
            m_y = b;
        }
        points.push_back(point);
    }
    // Set max_x point to (0,0) & calculate Atan
    for(int i = 0; i< N; i++){
        points[i].setpoint(points[i].x-max_x, points[i].y-m_y);
        points[i].setAtan(calcAtan(points[i]));
    }
    
    // Sort points by atan value
    sort(points.begin(), points.end(), comp);

    for(int i =0 ; i<N; i++){
        cout << "( "<<points[i].x <<" , "<<points[i].y << " )"<< endl;
    }

    shell1.push(0);
    shell2.push(0);
    shell2.push(1);
    int idx1, idx2;

    for (int i = 2; i< N; i++){
        idx1 = shell1.top();
        idx2 = shell2.top();
        while(CCW(points[idx1],points[idx2],points[i])>0){
            if(idx1 == 0){
                shell2.pop();
                shell2.push(i);
                break;
            }
            shell2.pop();
            shell1.pop();
            count--;

            idx1 = shell1.top();
            idx2 = shell2.top();
        }
        if(CCW(points[idx1], points[idx2], points[i])==0){
            shell2.pop();
            shell2.push(i);
        }
        else{
            shell1.push(idx2);
            shell2.push(i);
            count++;
        }
    }
    if(CCW(points[shell1.top()],points[shell2.top()],points[0])==0){
        shell2.pop();
        shell1.pop();
        count--;
    }
    // 여기에서 points[1]이 아니고 shell2[1]이 되어야 정확함
/*    else if(CCW(points[N-1],points[0],points[1])==0){
        count--;
    }*/

    while(!shell2.empty()){
        idx2 = shell2.top();
        cout << "idx2: "<< idx2<<" ("<<points[idx2].x<<" , "<< points[idx2].y << ")" << endl;
        if(idx2!=0 && points[idx2].x == 0)
            count_on ++;
        shell2.pop();
    }

    if(count_on>0){
        count = count-count_on +1;
    }

    cout << count;
}
