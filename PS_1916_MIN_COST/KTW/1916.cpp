#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#define cost first
#define des second
using namespace std;

typedef pair<int,int> edge;
typedef pair<int,int> node;

bool relax(int cities[], node& n, edge& e){
    if( cities[e.des] > n.cost + e.cost ){
        cities[e.des] = n.cost + e.cost;
        return true;
    }
    return false;
}

int findSPT(vector<vector<edge>> &Edges, int &N, int &start, int &end){
    int* cities = (int*) malloc (sizeof(int)*(N+1));
    for (int i = 1; i <= N; i++){
       if (i==start)
           cities[i] = 0;
       else 
           cities[i] = INT_MAX;
    }
    
    priority_queue<node,vector<node>,greater<node> > pq;
    pq.emplace(0,start);
    
    while(1){
        node tmp = pq.top();
        if ( tmp.des == end )
            return tmp.cost;
        pq.pop();
        
        if ( cities[tmp.des] < tmp.cost ) 
            continue;
        
        for( edge& i:Edges[tmp.des] )
            if (relax ( cities, tmp, i )) 
                pq.emplace(cities[i.des],i.des);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> Edges;
    Edges.resize(N+1);
    
    for (int m = 0; m < M; m++){
        int src,des,cost;
        cin >> src >> des >> cost;
        Edges[src].emplace_back(cost,des);
    }

    int start,end;
    cin >> start >> end;
    
    cout << findSPT(Edges, N, start, end) << endl;   
    return 0;
}
