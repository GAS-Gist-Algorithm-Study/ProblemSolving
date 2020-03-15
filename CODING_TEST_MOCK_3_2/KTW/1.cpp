#include<iostream>
using namespace std;
int life[8];
int weight[8];
int numberOfEggs;
int maxValue = 0;

void maxBreaking(int ith_egg);
bool ableToHit(int ith_egg);
bool otherEggsCleared(int ith_egg);
void breaking(int ith_egg, int target_egg);
void returnBreaking(int ith_egg, int target_egg);
int numberOfBrokenEggs(void);
 
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> numberOfEggs;
    for (int n = 0; n < numberOfEggs; n ++)
        cin >> life[n] >> weight[n];
    maxBreaking(0);
    cout << maxValue << "\n";
}

void maxBreaking(int ithEgg){
    if (ithEgg == numberOfEggs){
        maxValue = max(maxValue, numberOfBrokenEggs());
        return;
    }
    if (!ableToHit(ithEgg)){
        maxBreaking(ithEgg+1);
        return;
    }

    for(int targetEgg = 0; targetEgg < numberOfEggs; targetEgg++){
        if (ithEgg != targetEgg && life[targetEgg] > 0){
            breaking(ithEgg,targetEgg);
            maxBreaking(ithEgg+1);
            returnBreaking(ithEgg, targetEgg);
        }
    }
}

bool ableToHit(int ithEgg){
    if (life[ithEgg]<=0)
        return false; 
    if (otherEggsCleared(ithEgg))
        return false;
    return true;
}
 
bool otherEggsCleared(int ithEgg){
    for (int egg = 0; egg < numberOfEggs; egg++){
        if (egg == ithEgg)
            continue;
        if (life[egg] > 0)
            return false;
    }
    return true;
}

void breaking(int ithEgg, int targetEgg){
    life[ithEgg] -= weight[targetEgg];
    life[targetEgg] -= weight[ithEgg];
}

void returnBreaking(int ithEgg, int targetEgg){
    life[ithEgg] += weight[targetEgg];
    life[targetEgg] += weight[ithEgg];
}

int numberOfBrokenEggs(void){
    int brokenEggs = 0;
    for (int egg = 0; egg < numberOfEggs ; egg++)
        if (life[egg] <= 0)
            brokenEggs++;
    return brokenEggs;
}

