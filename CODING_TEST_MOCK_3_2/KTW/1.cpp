#include<iostream>
using namespace std;
int life[8];
int weight[8];
int numberOfEggs;
int MaxValue = 0;

bool AbleToHit(int ith_egg);
void MaxBreaking(int ith_egg);
bool OtherEggsCleared(int ith_egg);
void Breaking(int ith_egg, int target_egg);
void ReturnBreaking(int ith_egg, int target_egg);
int NumOfBrokenEggs(void);
 
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> numberOfEggs;
    for (int n = 0; n < numberOfEggs; n ++)
        cin >> life[n] >> weight[n];
    MaxBreaking(0);
    cout << MaxValue << "\n";
}

void MaxBreaking(int ith_egg){
    if (ith_egg == numberOfEggs){
        MaxValue = max(MaxValue, NumOfBrokenEggs());
        return;
    }
    if (!AbleToHit(ith_egg)){
        MaxBreaking(ith_egg+1);
        return;
    }

    for(int target_egg = 0; target_egg < numberOfEggs; target_egg++){
        if (ith_egg != target_egg && life[target_egg] > 0){
            Breaking(ith_egg,target_egg);
            MaxBreaking(ith_egg+1);
            ReturnBreaking(ith_egg, target_egg);
        }
    }
}

bool AbleToHit(int ith_egg){
    if (life[ith_egg]<=0)
        return false; 
    if (OtherEggsCleared(ith_egg))
        return false;
    return true;
}
 
bool OtherEggsCleared(int ith_egg){
    for (int egg = 0; egg < numberOfEggs; egg++){
        if (egg == ith_egg)
            continue;
        if (life[egg] > 0)
            return false;
    }
    return true;
}

void Breaking(int ith_egg, int target_egg){
    life[ith_egg] -= weight[target_egg];
    life[target_egg] -= weight[ith_egg];
}

void ReturnBreaking(int ith_egg, int target_egg){
    life[ith_egg] += weight[target_egg];
    life[target_egg] += weight[ith_egg];
}

int NumOfBrokenEggs(void){
    int BrokenEggs = 0;
    for (int egg = 0; egg < numberOfEggs ; egg++)
        if (life[egg] <= 0)
            BrokenEggs++;
    return BrokenEggs;
}

