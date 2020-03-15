#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
typedef pair<int, int> pii;

struct result{
    int point;
    int scoreSum;
    int cntPlus;
    result() {}
    result(int point, int scoreSum, int cntPlus) : point(point), scoreSum(scoreSum), cntPlus(cntPlus) {}
    bool operator <(const result &A) const{
        return scoreSum <A.scoreSum;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    vector<pii> paths[301];
    int startPoint, endPoint, score;
    for(int i=0;i<K;i++){
        cin >> startPoint >> endPoint >> score;
        if(startPoint < endPoint) paths[startPoint].emplace_back(make_pair(endPoint, score));
    }

    result start;
    start.point = 1;
    start.scoreSum = 0;
    start.cntPlus = 1;
    queue<result> q;
    priority_queue<pii, vector<pii>, less<pii> > results;

    q.emplace(start);
    while(!q.empty()){
        int curPoint = q.front().point;
        int curScore = q.front().scoreSum;
        int curCnt = q.front().cntPlus;
        int curSize = paths[curPoint].size();
        q.pop();
        
        for(int i=0;i<curSize;i++){
            int nextPoint = paths[curPoint][i].first;
            int nextScore = paths[curPoint][i].second + curScore;
            int nextCnt = curCnt++;
            if(nextPoint == N){
                if(nextCnt > M) continue;
                results.emplace(make_pair(nextScore, nextCnt));
            }
            q.emplace(result(nextPoint, nextScore, nextCnt));
        }
    }

    for(int i=0;i<results.size();i++){
        if(results.top().second > M) results.pop();
        else{
            cout << results.top().first << endl;
            break;
        }
    }

    return 0;
}