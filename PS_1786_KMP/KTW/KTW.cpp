#include <stdio.h>
#include <string.h>

char text[1000001];
char pattern[1000001];

void pattern_analysis(char* pattern, int* value, int M)
{
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

void KMP(char* text, char* pattern){

	int M = strlen(pattern);
	int N = strlen(text);
	int value[M];
	pattern_analysis(pattern, value,M);

	int i=0;
	int j=0;
	int where[N];
	int count =0;
	while(i<N){
		if(text[i]==pattern[j]){
			i++; j++;
		}
		if(j==M){
			where[count] = i-j+1;
			count++;
			j=value[j-1];
		}

		else if (i < N && pattern[j] != text[i]) { 
			if (j != 0) 
				j = value[j - 1]; 
			else
				i = i + 1; 
		}
	}
	printf("%d\n",count);
	for(int i=0; i<count;i++)
	{
		printf("%d ",where[i]);
	}
	
}

int main(){
	gets(text);
	gets(pattern);
	KMP(text, pattern);
	return 0;
}
