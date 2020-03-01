#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
int N, M;

class Comp{
    public:
    bool operator()(piii p1, piii p2){
        return p1.first <= p2.first;
    }
};

priority_queue<piii, vector<piii>, Comp> map;

void KMP(){
    while
}

int main (){
    cin >> N >> M;
    piii house;
    for(int i = 0; i<M; i++){
        cin >> house.second.first >> house.second.second >> house.first;
        map.push(house);
    }

}