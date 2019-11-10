#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char t[1000001], p[1000001];
int pi[1000001], anspos[1000001];

int main(){
	gets(t);
	gets(p);
	if(strlen(t) < strlen(p)){
		printf("0");
		return 0;
	}
	pi[0] = -1;
	int k = -1, ans = 0;
	for(int i=1; i <= strlen(p); i++){
		while(k >= 0 && p[k] != p[i-1]){
			k = pi[k];
		}
		k++;
		pi[i] = k;
	}
	
	for(int i=0; i<=strlen(t) - strlen(p);){
		int count = 1;
		for(int j=0; j<strlen(p); j++){
			if(t[i+j] != p[j]) break;
			count++;
		}
		
		if(count > strlen(p)){
			anspos[ans] = i+1;
			ans++;
		}
		
		i += count-1 - pi[count-1];
	}
	
	printf("%d\n",ans);
	for(int i=0; i<ans; i++)
		printf("%d\n", anspos[i]);
}
