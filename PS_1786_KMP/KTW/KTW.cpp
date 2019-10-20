#include <stdio.h>
#include <string.h>

//aabaabaaa
void pattern_analysis(char* pattern, int* value, int M){
	value[0]=0;
	int i = 1;
	int j = 0;
	while( i<M ){
		if (pattern[i]==pattern[j])
		{
			j++;
			value[i]=j;
			i++;
		}
		else //pattern[i]!=pattern[j]
		{
			if(j==0)
			{
				value[i]=0;
				i++;
			}
			else //value[i-1]!=0
			{
				j=value[j-1];
			}
		}
	}
}

void KMP(int* value, char* text, char* pattern,int N,int M){
	int i=0;
	int j=0;
	char* where;
	int count =0;
	while(i<N){
		if(text[i]==pattern[j]){
			i++; j++;
			if(j==M){
				where[count] = i-j+1;
				count++;
			}
		else // text[i]!=pattern[j]
		{
			j=value[j-1]+1;
			i= i-j+value[j-1]+1;
		}
		
		}
	}
	printf("%d",count);
	for(int i=0; i<sizeof(where);i++){
		printf("%d ",where[i]);
	}
}

int main(){
	char pattern[] = {"aabaabaaa"};
	char text[] = {"aaaabbaaabbababaabaabaaa"};
	int M = strlen(pattern);
	int N = strlen(text);
	int value[M];
	pattern_analysis(pattern, value,M);
//	KMP(value, text, pattern, N, M);
	for(int i=0;i<sizeof(pattern)-1;i++){
	
		printf("%c : %d\n",pattern[i],value[i]);
	}
	return 0;
}
