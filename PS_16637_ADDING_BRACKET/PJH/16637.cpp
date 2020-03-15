#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct node 
{
  node(int index, int num, char op): index(index), num(num), op(op) { }

  int index;
  int num;
  char op;
  vector<node*> nexts;
};

int calc(int a, int b, char op) 
{
  if (op == '+') 
    return a + b;
  else if (op == '-')
    return a - b;
  else if (op == '*')
    return a * b;
  else
    return -1;
}

void DFS(node* cur, int sum, int N, int &MAX) 
{
  if (cur->index == N) {
    MAX = max(sum, MAX);
    return;
  }

  for (node * next: cur->nexts) 
    DFS(next, calc(sum, next->num, next->op), N, MAX); 
}

void getOps(const string& expr, int N, char* ops) 
{
  for (int i = 0; i < N - 1; i++) 
    ops[i] = expr[i * 2 + 1];
}

void getNums(const string& expr, int N, char* ops, vector<node*>& nums) 
{
  nums.push_back(new node(0, expr[0] - '0', '+'));
  for (int i = 1; i < N; i++) 
    nums.push_back(new node(i, expr[i * 2] -'0', ops[i - 1]));
}

void getFatNums(const string& expr, int N, char* ops, 
                vector<node*>& nums, vector<node*>& fatNums) 
{
  if (N > 1)
    fatNums.push_back(new node(0, calc(nums[0]->num, nums[1]->num, ops[0]), '+'));
  for (int i = 1; i < N - 1; i++) 
    fatNums.push_back(
        new node(i, calc(nums[i]->num, nums[i + 1]->num, ops[i]), ops[i - 1])
    );
}

void connectNodes(vector<node*>& nums, vector<node*>& fatNums, int N) 
{
  for (int i = 0; i <= N - 2; i++) 
    nums[i]->nexts.push_back(nums[i+1]);
  for (int i = 0; i <= N - 3; i++) 
    nums[i]->nexts.push_back(fatNums[i+1]);
  for (int i = 0; i <= N - 3; i++) 
    fatNums[i]->nexts.push_back(nums[i+2]);
  for (int i = 0; i <= N - 4; i++) 
    fatNums[i]->nexts.push_back(fatNums[i+2]);
}

node* makeGraph(const string& expr, int N) 
{
  vector<node*> nums;
  vector<node*> fatNums;
  char ops[10];

  getOps(expr, N, ops);
  getNums(expr, N, ops, nums);
  getFatNums(expr, N, ops, nums, fatNums);
  connectNodes(nums, fatNums, N);

  node* startNode = new node(-1, 0, ' ');
  node* finishNode = new node(N, 0, '+');
  startNode->nexts.push_back(nums[0]);
  nums[N-1]->nexts.push_back(finishNode);
  if (N > 1) {
    startNode->nexts.push_back(fatNums[0]);
    fatNums[N-2]->nexts.push_back(finishNode);
  }

  return startNode;
}

int main() 
{
  int N = 0;
  int MAX = 0x80000000;
  string expr = "";

  cin >> N 
      >> expr;

  N = (N + 1) / 2;
  node* startNode = makeGraph(expr, N);
  DFS(startNode, 0, N, MAX);

  cout << MAX << endl;
}
