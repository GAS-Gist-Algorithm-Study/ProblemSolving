#include<iostream>
using namespace std;
pair<int,int> cache[41];

pair<int,int> fibonacci(int n) {
    if (cache[n].first)
        return cache[n];
    if ( n == 0 )
        return cache[n] = make_pair(1,0);
    if ( n == 1 )
        return cache[n] = make_pair(0,1);
    pair<int,int> x = fibonacci(n-1);
    return cache[n] = make_pair(x.second, x.first+x.second);
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
       int n;
       cin >> n;
       pair<int, int> x = fibonacci(n);
       cout << fibonacci(n).first << " " << fibonacci(n).second << "\n";
    }
}
