#include<iostream>
#include<vector>

using namespace std;

struct node{
    node() { visited = false; }
    bool visited;
    vector<node*> nexts;
};

int countConnected(node* node1, int& cnt){
    for(int i=0;i<node1->nexts.size();i++)
        if(node1->nexts[i]->visited == false){
            node1->nexts[i]->visited = true;
            cnt++;
            countConnected(node1->nexts[i], cnt);
        }
    
    return cnt;
}

int main(){
    int num, edge;
    cin >> num >> edge;

    node* nodes[101];

    for(int i=0;i<=num;i++)
        nodes[i] = new node();

    int temp1, temp2;

    for(int i=0;i<edge;i++){
        cin >> temp1 >> temp2;
        nodes[temp1]->nexts.emplace_back(nodes[temp2]);
        nodes[temp2]->nexts.emplace_back(nodes[temp1]);
    }

    int cnt=0;
    nodes[1]->visited = true;

    cout << countConnected(nodes[1], cnt) << endl;

    return 0;
}