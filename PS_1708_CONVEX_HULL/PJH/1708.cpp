#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[100001];

struct point 
{
  long long x, y;

  point(long long x, long long y) : x(x), y(y) { }

  point operator - (const point& a) const 
  { return { x - a.x, y - a.y }; }

  bool operator < (const point& a) const 
  { return (x == a.x) ? y < a.y : x < a.x; }
};

long long ccw(point ab, point bc)
{ return ab.x * bc.y - ab.y * bc.x; }

long long ccw(point a, point b, point c) 
{ return ccw(b - a, c - b); }

void findHull(int N, vector<point>& pts, vector<point*>& hull)
{
  int last = 1;
  int i = 2;

  while (i <= N) {
    while (last > 0 && ccw(*hull[last - 1], *hull[last], pts[i]) <= 0) {
      hull.pop_back();
      last--;
    }
    hull.push_back(&pts[i++]);
    last++;
  }
}

void preprocess(vector<point>& pts, vector<point*>& hull)
{
  point minPoint = *min_element(pts.begin(), pts.end());

  sort(pts.begin(), pts.end()
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

int main(void)
{
  int N;
  vector<point> pts;
  vector<point*> hull;

  getInput(N, pts);
  preprocess(pts, hull);
  findHull(N, pts, hull);
 
  cout << hull.size() - 1 << endl;
  return 0;
}
