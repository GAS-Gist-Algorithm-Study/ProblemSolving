#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int value;
        vector<Node*> adj;
        Node(int i){
            value = i;
        }
};

int comp;
int pr;
vector<Node*> list;
bool visited[101];

int DFS(Node* node);

int main(){
    cin >> comp;
    cin >> pr;
    for(int i=1;i<comp+1;i++){
        Node* node = new Node(i);
        list.push_back(node);
    }
    for(int i = 1; i< pr+1; i++){
        int a,b;
        cin >> a >> b;
        list[a-1]->adj.push_back(list[b-1]);
        list[b-1]->adj.push_back(list[a-1]);
    }

    visited[0] = true;
    cout<< DFS(list[0]);
}

int DFS(Node* node){
    int count = 0;

    for(int j = 0; j<node->adj.size(); j++){
        int l = node->adj[j]->value-1;
        if(!visited[l]){
            visited[l] = true;
            count+= DFS(list[l])+1;
            }
        }
    return count;
}