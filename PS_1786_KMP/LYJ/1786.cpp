#include<iostream>
#include<vector>

using namespace std;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);

    int j=0;
    for(int i=1;i<patternSize;i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern, vector<int>& index){
    vector<int> table = makeTable(pattern);

    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j=0;
    int cnt=0;

    for(int i=0;i<parentSize;i++){
        while(j>0 && parent[i] != pattern[j]){
            j=table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j==patternSize-1){
                cnt++;
                index.push_back(i - patternSize + 2);
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
    cout << cnt <<endl;
}

int main(){
    vector<int> index;
    string pattern;
    string parent;
    getline(cin,parent,'\n');
    getline(cin,pattern,'\n');

    KMP(parent,pattern,index);

    for(int i=0;i<index.size();i++){
        cout << index[i] << " ";
    }
    cout << endl;
    
    return 0;
}