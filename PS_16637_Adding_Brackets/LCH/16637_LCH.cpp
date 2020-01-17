#include <cstdio>
#include <stack>
using namespace std;

int normal[20], manipulated[19], op[19], n, Max = -2147483647;
stack<pair<int, int> > s;

void ret(int to_compare){
	if(Max < to_compare) Max = to_compare;
}

int main(){
	int cal[9];
	char sik[20];
	
	scanf("%d", &n);
	scanf("%s", sik);
	for(int i=0; i<n; i++){
		switch(sik[i]){
			case '+':
				op[(i-1) / 2] = 0;
				break;
			case '-':
				op[(i-1) / 2] = 1;
				break;
			case '*':
				op[(i-1) / 2] = 2;
				break;
			default:
				normal[i / 2] = sik[i] - '0';
		}
	}
	
	for(int i=0; i<n/2; i++){
		switch(op[i]){
			case 0:
				manipulated[i] = normal[i] + normal[i+1];
				break;
			case 1:
				manipulated[i] = normal[i] - normal[i+1];
				break;
			case 2:
				manipulated[i] = normal[i] * normal[i+1];
		}
	}
	
	s.push({1, normal[0]});
	s.push({2, manipulated[0]});
	
	while(!s.empty()){
		pair<int, int> temp = s.top();
		s.pop();
		if(temp.first > n) continue;
		
		if(temp.first == n || temp.first == n-1){
			ret(temp.second);
			continue;
		}
		
		if(temp.first == n-2 || temp.first == n-3){
			switch(op[n/2-1]){
				case 0:	
					ret(temp.second + normal[n/2]);
					break;
				case 1:
					ret(temp.second - normal[n/2]);
					break;
				case 2:
					ret(temp.second * normal[n/2]);
			}
			continue;
		}
		
		if(temp.first % 2){
			switch(op[temp.first/2]){
				case 0:
					s.push({temp.first+2, temp.second + normal[(temp.first+2)/2]});
					s.push({temp.first+3, temp.second + manipulated[(temp.first+2)/2]});
					break;
				case 1:
					s.push({temp.first+2, temp.second - normal[(temp.first+2)/2]});
					s.push({temp.first+3, temp.second - manipulated[(temp.first+2)/2]});
					break;
				case 2:
					s.push({temp.first+2, temp.second * normal[(temp.first+2)/2]});
					s.push({temp.first+3, temp.second * manipulated[(temp.first+2)/2]});
			}
			continue;
		}
		
		switch(op[temp.first/2]){
			case 0:
				s.push({temp.first+3, temp.second + normal[(temp.first+3)/2]});
				s.push({temp.first+4, temp.second + manipulated[(temp.first+3)/2]});
				break;
			case 1:
				s.push({temp.first+3, temp.second - normal[(temp.first+3)/2]});
				s.push({temp.first+4, temp.second - manipulated[(temp.first+3)/2]});
				break;
			case 2:
				s.push({temp.first+3, temp.second * normal[(temp.first+3)/2]});
				s.push({temp.first+4, temp.second * manipulated[(temp.first+3)/2]});
		}
	}
	
	printf("%d", Max);
}
