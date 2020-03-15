#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int id[100001];
int totalcost;
int last_cost;
int M, N;

struct Edge{
    int V1;
    int V2;
    int cost;
};

vector<Edge> PQ;

int find_id(int n){
    if(id[n] == n){
        return n;
    }
    else
        return id[n] = find_id(id[n]);
}

void set_union(int a, int b) {
  int A = find_id(a);
  int B = find_id(b);
  if (B < A)
    id[A] = B;
  else 
    id[B] = A;
}

void Kruskal(){
    int count = 0;
    sort(PQ.begin(), PQ.end(), 
         [](Edge& E1, Edge& E2){
        return E1.cost < E2.cost;
    }
        );
    for(auto e: PQ){       
        if(count == N-1){
            break;
        }

        if(find_id(e.V1) != find_id(e.V2)){
            set_union(e.V1,e.V2);
            //cout << "id of V1 (" << front.V1 << "): " << id[front.V1] << ", id of V2 (" << front.V2 << "): " << id[front.V2] << endl;
            last_cost = e.cost;
            totalcost = totalcost + last_cost;
            count++;
        }
    }  
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Edge edge;
    int cost, a, b;
    cin >> N >> M;

    for(int i =0 ; i<M; i++){
        cin >> edge.V1 >> edge.V2 >> edge.cost;
        PQ.push_back(edge);
    }
    
    for(int i = 0; i<N+1; i++){
        id[i] = i;
    }

    Kruskal();

    totalcost = totalcost - last_cost;
    cout << totalcost;
}