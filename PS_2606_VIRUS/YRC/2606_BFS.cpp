#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int value;
        vector<Node*> adj;
    Node(int i){
        value = i;
    }
};

bool visited[101];
vector<Node*> list;

int BFS(){
    int count=0;
    queue<Node*> order;
    order.push(list[0]);
    visited[0] = true;

    while(!order.empty()){
        Node* root = order.front();
        for(int j = 0; j<root->adj.size();j++){
            Node* adjnode = root->adj[j];
            if(!visited[adjnode->value-1]){
                visited[adjnode->value-1] = true;
                order.push(adjnode);
            }
        }
        count ++;
        order.pop();
    }
    cout<< endl;
    return count -1;
}

int main(){
    int computer, computerpair, a, b;
    cin>> computer>> computerpair;
    for(int i = 1; i< computer+1; i++){
        Node* node = new Node(i);
        list.push_back(node);
    }

    for(int i = 0;i<computerpair;i++){
        cin >> a >> b;
        list[a-1]->adj.push_back(list[b-1]);
        list[b-1]->adj.push_back(list[a-1]);
    }
    cout << BFS();
}