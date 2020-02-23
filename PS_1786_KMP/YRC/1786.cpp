#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;


vector<int> makeTable(string & pattern){
    vector<int> table(pattern.size(), 0);
    int j = 0;
    int len = pattern.size();

    for(int i = 1; i< len; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }

        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

vector <int> KMP(string & pattern, string& text){
    vector<int> table = makeTable(pattern);
    int text_len = text.size();
    int pattern_len = pattern.size();
    int j = 0;
    vector<int> positions;

    for(int i = 0; i< text_len; i++){
        while(j>0 && text[i] != pattern[j]){
            j = table[j-1];
        }

        if(text[i] == pattern[j]){
            if(j == pattern_len-1){
                positions.push_back(i-pattern_len+2);
                j = table[j];
            } 
            else{ 
                j++;} 
        }
    }
    return positions;
}

int main (){
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    vector<int> indices = KMP(pattern,text);

    cout << indices.size() << endl;
    for(int i = 0; i< indices.size(); i++){
        cout << indices[i] << " "; }
}