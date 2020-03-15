#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Egg
{
    public:
    int hp, weight, index;
    Egg(){}
    Egg(int h, int w, int i){
        hp = h;
        weight = w;
        index = i;
    }
};

void findMax(vector<Egg> eggs, int& maxEgg, int id)
{
    int count = 0;
    for(int i = 0; i < eggs.size(); i++){
        if(eggs[i].hp <= 0)
            count ++;
    }
    maxEgg = max(maxEgg , count);

    if(id == eggs.size()){
        return;
    }

    if(eggs[id].hp <=0){
        findMax(eggs, maxEgg, id+1);
        return;
    }

    vector<Egg> unbroken;

        for(int i = 0; i < eggs.size(); i++){
            if(eggs[i].hp > 0 && i != id){
                unbroken.emplace_back(eggs[i]);
            }
        }

    for(Egg e : unbroken){
        eggs[id].hp -= eggs[e.index].weight;
        eggs[e.index].hp -= eggs[id].weight;

        findMax(eggs, maxEgg, id+1);

        eggs[id].hp += eggs[e.index].weight;
        eggs[e.index].hp += eggs[id].weight;
    }
}

int getMax(vector<Egg> eggs, int id){
    int maxEggs = 0;
    findMax(eggs, maxEggs, id);
    return maxEggs;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S, W;
    vector<Egg> eggs;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S >> W;
        eggs.emplace_back(S, W, i);
    }

    cout << getMax(eggs, 0);
}