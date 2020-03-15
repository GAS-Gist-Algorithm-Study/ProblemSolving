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

int findSPT(vector<edge>* Edges, int &N, int &start, int &end){
    int* cities = (int*) malloc (sizeof(int)*(N+1));
    fill(cities,cities+N+1,INT_MAX);
    //fill이 시간이 조금 더 걸리는듯
    cities[start] = 0;
    
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
            if ( relax ( cities, tmp, i )) 
                pq.emplace(cities[i.des],i.des);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<edge> Edges[N+1];
    
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
