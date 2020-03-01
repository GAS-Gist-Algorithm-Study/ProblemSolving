#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

void Prim(vector<pii>* City, int sp, int ep, int* cost, bool* visited){
    stack<int> order;
    order.push(sp);
    cost[sp] = 0;
    visited[sp] = true;

    while(!order.empty()){
        int top = order.top();
        for(int i = 0; i < City[top].size(); i++){
            int now = City[top][i].first;
            if(!visited[now]){
                order.push(now);
                visited[now] = true;
                int new_cost = City[top][i].second + cost[top];
                cout << "top: "<<top << " now: " << now <<" cost: "<< cost[now] << " new_cost: "<< new_cost ;
                if(cost[now]> new_cost){
                    cost[now] = new_cost;
                }
                cout << " cost_now: "<<cost[now] << endl;
            }
        }
        order.pop();
    }    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, sp, ep;
    cin >> N >> M;
    vector<pii> City[1001];
    bool visited[1001];
    int cost[1001];
    for(int i = 0; i< N+1; i++){
        cost[i] = 1000000001;
        visited[i] = false;
    }

    for(int i = 0; i<M; i++){
        int a, b, cst;
        cin >> a >> b >> cst;
        City[b].push_back(make_pair(a,cst));
        City[a].push_back(make_pair(b,cst));
    }
    cin >> sp >> ep;
    Prim(City,sp,ep,cost,visited);
    cout << cost[ep];
}