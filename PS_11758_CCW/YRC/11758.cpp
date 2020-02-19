# include <iostream>
# include <cmath>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int CCW(pii p1, pii p2, pii p3){
    pii vec1, vec2;
    vec1.first = p2.first-p1.first;
    vec2.first = p3.first - p2.first;
    vec1.second = p2.second - p1.second;
    vec2.second = p3.second - p2.second;

    return (vec1.first*vec2.second - vec1.second*vec2.first);
}

int main (){
    pii p1, p2, p3;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;

    if (CCW(p1,p2,p3)==0)
        cout << "0";
    else if(CCW(p1,p2,p3)>0)
        cout << "1";
    else cout << "-1";
}
