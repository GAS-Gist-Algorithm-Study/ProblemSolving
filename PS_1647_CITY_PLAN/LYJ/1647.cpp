#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int root[100001];

class Road{
    public:
        int firstHouse;
        int secondHouse;
        int cost;
        bool operator < (const Road &A) const{
            return cost < A.cost;
        }
};

void initRoot(int houseNum){
    for(int i=1;i<=houseNum;i++){
        root[i]=i;
    }
}

int find(int u){
    if(root[u]==u) return u;
    else return root[u] = find(root[u]);
}

void merge(int u, int v){
    int uRoot = find(u);
    int vRoot = find(v);

    root[vRoot]=uRoot;
}

int main(){
    int houseNum, roadNum;
    cin >> houseNum >> roadNum;

    vector<Road> roads;
    Road temp;
    for(int i=0;i<roadNum;i++){
        cin >> temp.firstHouse >> temp.secondHouse >> temp.cost;
        roads.emplace_back(temp);
    }
    sort(roads.begin(),roads.end());

    for(int i=1;i<=houseNum;i++)
        root[i]=i;

    int sum=0;
    int cnt=0;
    for(int i=0;i<roadNum;i++){
        if(find(roads[i].firstHouse) != find(roads[i].secondHouse)){
            sum+=roads[i].cost;
            merge(roads[i].firstHouse, roads[i].secondHouse);
            cnt++;
        }
        if(cnt == houseNum-2) break;
    }

    cout << sum  << endl;
}