#include<iostream>
using namespace std;
long long cache[91];
long long FibonacciNum(int n){
    if (cache[n])
       return cache[n]; 
    if ( n == 0 )
        return cache[n] = 0;
    if ( n == 1 )
        return cache[n] = 1;
    return cache[n] = FibonacciNum(n-1)+FibonacciNum(n-2);
}

int main(){
    int n;
    cin >> n;
    cout << FibonacciNum(n);
    return 0;
}
