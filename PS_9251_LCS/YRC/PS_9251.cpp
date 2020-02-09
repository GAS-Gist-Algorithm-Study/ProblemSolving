#include <iostream>
#include <cstring>

using namespace std;
int LCS[1001][1001];

int DP(int ind1, int ind2, char * arr1, char* arr2){
    if(ind1<0 || ind2<0){
        return 0;
    }

    if(LCS[ind1][ind2]){
        return LCS[ind1][ind2];
    }

    if(arr1[ind1] == arr2[ind2]){
        return LCS[ind1][ind2] = 1+DP(ind1-1,ind2-1,arr1,arr2);
    }

    else{
        return LCS[ind1][ind2] = max(DP(ind1-1,ind2,arr1,arr2),DP(ind1,ind2-1,arr1,arr2));
    }
}

int main (){
    char str1[1001];
    char str2[1001];

    cin >> str1 >> str2;
    cout << DP(strlen(str1)-1,strlen(str2)-1,str1, str2);
}