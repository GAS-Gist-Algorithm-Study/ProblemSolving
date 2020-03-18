#include<iostream>
#include<vector>
using namespace std;
int continuousSum(const vector<int> v,vector<int> minSum, int n){
    int sum = 0;
    minSum[0] = 0;
    int ans;
    for ( int i = 0; i < n; i++ ){
        sum = sum + v[i];
        minSum[i+1] = sum < minSum[i]? sum : minSum[i];
        if( i == 0 )
            ans = sum;
        else
            ans = max(ans, sum-minSum[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> minSum;
    v.resize(n);
    minSum.resize(n+1);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << continuousSum(v,minSum,n);
}
