#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point; 

long long ccw(point ab, point bc);
long long ccw(point a, point b, point c);
long long ccw(point* a, point* b, point* c);

void preprocess(vector<point>& pts, vector<point*>& hull);
void getInput(int& N, vector<point>& pts);
void findHull(int N, vector<point>& pts, vector<point*>& hull, int i);
void printHull(vector<point*> hull);

int main(void)
{
  int N;
  vector<point> pts;
  vector<point*> hull;

  getInput(N, pts);
  preprocess(pts, hull);
  findHull(N, pts, hull, 2);
 
  cout << hull.size() - 1 << endl;
  return 0;
}

struct point 
{
  long long x, y;

  point(long long x, long long y) : x(x), y(y) { }

  point operator - (const point& a) const 
  { return { x - a.x, y - a.y }; }

  bool operator < (const point& a) const 
  { return (x == a.x) ? y < a.y : x < a.x; }
};

void findHull(int N, vector<point>& pts, vector<point*>& hull, int target)
{
  if (target > N)
    return;

  /*
   * If you get the hull right, ccw with a line and pts[target]
   * should always be larger than 0.
   */
  while (hull.size() > 1 && 
      ccw(hull[hull.size() - 2], hull[hull.size() - 1], &pts[target]) <= 0)
    hull.pop_back();

  hull.push_back(&pts[target]);
  findHull(N, pts, hull, target + 1);
}

void printHull(vector<point*> hull)
{
  for (auto pp: hull)
    cout << pp-> x << " " << pp->y << endl;
}

void preprocess(vector<point>& pts, vector<point*>& hull)
{
  /*
   * Sorting by the distance from the minimum point beforehand
   * is crucial, since you want to check the closer points 
   * when some points are on the same line from the minimium point.
   */
  sort(pts.begin(), pts.end());
  point minPoint = pts[0];

  stable_sort(pts.begin(), pts.end()
      , [&minPoint](point a, point b) { 
        point ma = a - minPoint;
        point mb = b - minPoint;

        return ma.y * mb.x < ma.x * mb.y;
  });
  pts.emplace_back(pts[0].x, pts[0].y);

  hull.push_back(&pts[0]);
  hull.push_back(&pts[1]);
}

void getInput(int& N, vector<point>& pts)
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    pts.emplace_back(x, y);
  }
}

long long ccw(point ab, point bc)
{ return ab.x * bc.y - ab.y * bc.x; }

long long ccw(point a, point b, point c) 
{ return ccw(b - a, c - b); }

long long ccw(point* a, point* b, point* c) 
{ return ccw(*b - *a, *c - *b); }
