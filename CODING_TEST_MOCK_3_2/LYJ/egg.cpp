#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct egg{
    int strength;
    int weight;
    egg(){}
    egg(int strength, int weight) : strength(strength), weight(weight) { }
};

int breakEggs(vector<egg> &eggs, int i, int N){
    //끝까지 다 봄
    if(i == N){
    int numBrok = 0;
        for(int j=0;j<N;j++){
            if(eggs[j].strength <= 0) numBrok++;
        }
        return numBrok;
    }

    //들고 있는것이 깨짐
    if(eggs[i].strength <= 0) return breakEggs(eggs, i+1, N);

    int ret = 0;
    bool flag = false;
    //하나 들고 다를 것 하나 깨는 여러 경우들 만들기
    for(int j=0;j<N;j++){
        if(j == i) continue;
        if(eggs[j].strength <= 0) continue;
        flag = true;

        eggs[i].strength-=eggs[j].weight;
        eggs[j].strength-=eggs[i].weight;

        ret = max(breakEggs(eggs, i+1, N), ret);

        eggs[i].strength+=eggs[j].weight;
        eggs[j].strength+=eggs[i].weight;
    }

    // 마지막 원소이자 본인일때
    if(!flag) return breakEggs(eggs, i+1, N);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<egg> eggs;
    eggs.resize(N);
    for(int i=0;i<N;i++)
        cin >> eggs[i].strength >> eggs[i].weight;

    cout << breakEggs(eggs, 0, N) << '\n';

    return 0;
}