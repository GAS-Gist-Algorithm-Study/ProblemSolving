#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int,int> pii;

stack<int> s;
queue<int> q;
vector<int> v[1001];
bool visited[1001];

int main(){
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for(int i=0; i<m; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	//DFS
	for(int i=0; i<n; i++)
		sort(v[i].begin(), v[i].end(), greater<int>());
	
	for(int i=0; i<v[start].size(); i++)
		s.push(v[start][i]);
	visited[start] = true;
	printf("%d ", start);
	while(!s.empty()){
		int temp = s.top();
		s.pop();
		if(!visited[temp]){
			printf("%d ", temp);
			visited[temp] = true;
			for(int i=0; i<v[temp].size(); i++){
				if(!visited[v[temp][i]]){
					s.push(v[temp][i]);
				}
			}
		}
	}
	
	printf("\n");
	
	//BFS
	for(int i=0; i<=n; i++)
		visited[i] = false;
	
	for(int i=0; i<n; i++)
                sort(v[i].begin(), v[i].end());

        for(int i=0; i<v[start].size(); i++)
                q.push(v[start][i]);
        visited[start] = true;
        printf("%d ", start);
        while(!q.empty()){
                int temp = q.front();
                q.pop();
                if(!visited[temp]){
                        printf("%d ", temp);
                        visited[temp] = true;
                        for(int i=0; i<v[temp].size(); i++){
                                if(!visited[v[temp][i]]){
                                        q.push(v[temp][i]);
                                }
			}
		}
	}
}
