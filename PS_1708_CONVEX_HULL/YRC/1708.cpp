# include <iostream>
# include <vector>
# include <algorithm>
# include <stack>

using namespace std;

class Point{
public:
    long long x, y;
    double angle;
    void setpoint(long long nx, long long ny){
        x = nx;
        y = ny;
    }
};

bool comp (const Point& p1, const Point& p2){
    if (p1.y*p2.x < p1.x*p2.y) return false;
    else if (p1.y*p2.x == p2.y*p1.x){
        if(p1.x == p2.x)
            return p1.y > p2.y;
        else return p1.x > p2.x;
    }
    else return true;
}

double CCW(Point& start, Point& end, Point& np){
    double v1_x = end.x - start.x;
    double v1_y = end.y - start.y;
    double v2_x = np.x - end.x;
    double v2_y = np.y - end.y;

    return ((v1_x*v2_y)-(v1_y*v2_x));
}

void printpoints(Point* points, int N){
    for(int i =0 ; i<N; i++){
        cout << "( "<<points[i].x <<" , "<<points[i].y << " )"<< endl;
    }
}

int main (){
    int N;
    cin >> N;
    stack <int> shell1;
    stack <int> shell2;
    int max_x_id;
    long long max_x = -40001;
    long long m_y = -40001;

    int count = 2;
    vector<Point> points;
    
    for (int i = 0; i< N; i++){
        Point point;
        int a, b;
        cin >> a >> b;
        point.setpoint(a,b);
        if(a > max_x){
            max_x_id = i;
            max_x = a;
            m_y = b;
        }
        else if(a==max_x){
            if(b>m_y){
                max_x_id = i;
                max_x = a;
                m_y = b;
            }
        }
        points.push_back(point);
    }
    // Set max_x point to (0,0)
    for(int i = 0; i< N; i++){
        points[i].setpoint(points[i].x-max_x, points[i].y-m_y);
    }
    
    // Sort points by angle
    sort(points.begin(), points.end(), comp);

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

    cout << count;
}