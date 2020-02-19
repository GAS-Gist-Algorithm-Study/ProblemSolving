#include <iostream>
#define pii pair<int, int>

using namespace std;

struct Point 
{
  int x, y;

  Point operator -(const Point &P) const 
  {
    return { x - P.x, y - P.y };
  }
};

int CCW(Point a, Point b, Point c)
{
  Point ab = b - a;
  Point bc = c - b;

  return ab.x * bc.y - ab.y * bc.x;
}

int main(void) 
{
  Point pts[3];

  for (int i = 0; i < 3; i++)
    cin >> pts[i].x >> pts[i].y;

  int ccw = CCW(pts[0], pts[1], pts[2]);

  if (ccw > 0)
    cout << 1;
  else if (ccw < 0)
    cout << -1;
  else
    cout << 0;

  endl(cout);
  return 0;
}
