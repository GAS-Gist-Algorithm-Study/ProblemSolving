#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
int table[1001][1001]={0,};
int visited[1001] = {0,};
int visited2[1001]= {0,};
int main(){
	int n, m , v, x, y;
	scanf("%d %d %d",&n,&m,&v);
	for(int i; i < m; i++){
		scanf("%d %d", &x,&y);
		table[x][y]= 1;
		table[y][x]= 1;
	}
	
	//dfs
	
	std::stack <int> st;
	st.push(v);
	printf("%d ",v);
	visited[v]=1;
	while(!st.empty()){
		int a = 0;
		int temp = st.top();
		for(int i=1;i<n+1;i++)
		{
			if(table[temp][i] && !visited[i])
			{
				st.push(i);
				visited[i]=1;
				a=1;
				printf("%d ",i);
				break;
			}
		}
		if(!a){
			st.pop();
		}
	}
	printf("\n");
	
	std:: queue <int> q;
	q.push(v);
	visited2[v]=1;
	printf("%d ", v);
	
	while(!q.empty()){
		int temp = q.front();
		for(int i=1; i< n+1; i++){
			if(table[temp][i] && !visited2[i])
			{
				q.push(i);
				printf("%d ", i);
				visited2[i] =1;
			}
		}
		q.pop();
	}
	
	
	return 0;
}

