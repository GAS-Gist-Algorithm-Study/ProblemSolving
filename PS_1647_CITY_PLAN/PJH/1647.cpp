#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

#define edge pair<int, pair<int, int>>
#define cost first
#define src second.first
#define dst second.second

using namespace std;

struct Union {
  int N;
  int* parent;

  Union(int N): N(N) 
  {
    parent = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
      parent[i] = i;
  }

  int find (int a) 
  {
    if (parent[a] == a)
      return a;
    else
      return parent[a] = find(parent[a]);
  }

  bool merge (int a, int b) 
  {
    int A = find(a);
    int B = find(b);

    if (A == B)
      return false;
    
    if (A < B)
      parent[B] = A;
    else 
      parent[A] = B;

    return true;
  }
};

void findMST(int N, vector<edge>& edges, vector<edge>& mst)
{
  Union U(N);
  sort(edges.begin(), edges.end());

  for (edge& e: edges) {
    if (mst.size() == N - 1)
      break;

    if (!U.merge(e.src, e.dst))
      continue;

    mst.emplace_back(e);
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<edge> edges(M);
  vector<edge> mst;

  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;

    edges[i].cost = C;
    edges[i].src = A;
    edges[i].dst = B;
  }

  findMST(N, edges, mst);

  int sum = accumulate(mst.begin(), mst.end(), 0,
    [](int acc, edge& e) { return acc + e.cost; });

  edge& max_edge = *max_element(mst.begin(), mst.end(), 
    [](edge& a, edge& b) { return a.cost < b.cost; });
    
  cout <<  sum - max_edge.cost << endl;
  return 0;
}
