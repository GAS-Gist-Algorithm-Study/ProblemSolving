#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int visited[1000] = { 0, };
int adj[1000][1000];
int main()
{
	int n, m, s;
	

	scanf("%d %d %d", &n, &m, &s);
	s--;
	for (int i = 0; i < n; i++)visited[i] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adj[i][j] = 0;
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s - 1][e - 1] = 1;
		adj[e - 1][s - 1] = 1;
	}

	stack<int> s1;
	s1.push(s);
	visited[s] = 1;
	printf("%d ", s+1);
	while (!s1.empty()) {
		int curn = s1.top(), f = 0;
		visited[curn] = 1;
		for (int i = 0; i < n; i++) {
			if (adj[curn][i] && !visited[i]) {
				s1.push(i);
				printf("%d ", i + 1);
				f = 1;
				break;
			}
		}
		if (!f)
			s1.pop();
	}
	printf("\n");

	for (int i = 0; i < n; i++) visited[i] = 0;
	queue<int> q1;
	q1.push(s);
	visited[s] = 1;
	while (!q1.empty()) {
		int curn = q1.front(), f = 0;
		visited[curn] = 1;
		printf("%d ", curn + 1);
		for (int i = 0; i < n; i++) {
			if (adj[curn][i] && !visited[i]) {
				visited[i] = 1;
				q1.push(i);
			}
		}
		q1.pop();
	}
}