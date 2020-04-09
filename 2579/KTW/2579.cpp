#include<iostream>
#include<vector>
using namespace std;
int caseStudy[4];

void compareCase(vector<int> v, int stair){
    int c0 = caseStudy[0];
    int c1 = caseStudy[1];
    int c2 = caseStudy[2];
    int c3 = caseStudy[3];
    
    caseStudy[0] = c2;
    caseStudy[1] = max(c0,c3) + v[stair];
    caseStudy[2] = c1 + v[stair];
    caseStudy[3] = c1;
}

int playGame(vector<int> v, int n){
    for ( int i = 3; i < n; i++ )
        compareCase(v, i);
    return max ( caseStudy[1], caseStudy[2] );//마지막 계단 밟아야..
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for ( int i = 0; i < n; i++ )
        cin >> v[i];
    if ( n == 1)
        cout << v[0];
    else if ( n == 2 )
        cout << v[0]+v[1];
    else if ( n == 3 )
        cout << v[0]+v[1]+v[2] - min(v[0],v[1]); 
    else{
        caseStudy[0] = v[0] + v[1];
        caseStudy[1] = v[0] + v[2];
        caseStudy[2] = v[1] + v[2];
        caseStudy[3] = v[1];
        cout << playGame(v, n);
    }
}
