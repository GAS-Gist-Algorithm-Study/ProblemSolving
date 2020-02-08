#include <iostream>
#include <vector>
#define WALL true
#define yx pair<int, int>
#define y first
#define x second

using namespace std;

class Pipe
{
  public:
    Pipe() 
    {
      state = 1;
      pos = {0, 0};
    }

    void turnLeft() { state = max(state - 1, 1); }
    void turnRight() { state = min(state + 1, 3); }
    int getState() { return state; }
    yx getPosition() { return pos; }

    void printYX() {
      cout << "y: " << pos.y << " x: " << pos.x << endl;
    }

    void push(int direction);
    vector<yx> getOccupyingBlock();

  private:
    int state;
    yx pos;
};

class House
{
  public:
    House(int n) { size = n; }

    Pipe* getPipe() { return &pipe; }
    bool isPipeValid();
    bool hasPipeArrived();
    void getInput();

  private:
    int size = 0;
    bool map[16][16];
    Pipe pipe;
};

int dfs(House& house, Pipe* pipe)
{
  if (house.hasPipeArrived())
    return 1;

  int sum = 0;
  int state = pipe->getState();

  switch (state) {
  case 1:
    pipe->push(1);
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->push(-1);

    pipe->push(1);
    pipe->turnRight();
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->turnLeft();
    pipe->push(-1);
    break;
  case 2:
    pipe->push(1);
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->push(-1);

    pipe->push(1);
    pipe->turnLeft();
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->turnRight();
    pipe->push(-1);

    pipe->push(1);
    pipe->turnRight();
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->turnLeft();
    pipe->push(-1);
    break;
  case 3:
    pipe->push(1);
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->push(-1);

    pipe->push(1);
    pipe->turnLeft();
    if (house.isPipeValid()) 
      sum += dfs(house, pipe); 
    pipe->turnRight();
    pipe->push(-1);
    break;
  }
  
  return sum;
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;

  House house(N); 
  house.getInput();
  Pipe* pipe = house.getPipe();

  cout << dfs(house, pipe) << endl;
  return 0;
}

void Pipe::push(int direction)
{
  switch (state) {
  case 1:
    pos = {pos.y, pos.x + direction};
    break;
  case 2:
    pos = {pos.y + direction, pos.x + direction};
    break;
  case 3:
    pos = {pos.y + direction, pos.x};
    break;
  }
}

vector<yx> Pipe::getOccupyingBlock()
{
  vector<yx> block;
  
  block.emplace_back(pos);

  switch (state) {
  case 1:
    block.emplace_back(pos.y, pos.x + 1);
    break;
  case 2:
    block.emplace_back(pos.y, pos.x + 1);
    block.emplace_back(pos.y + 1, pos.x);
    block.emplace_back(pos.y + 1, pos.x + 1);
    break;
  case 3:
    block.emplace_back(pos.y + 1, pos.x);
    break;
  }

  return block;
}

bool House::isPipeValid()
{
  for (yx& pos: pipe.getOccupyingBlock()) {
    if (map[pos.y][pos.x] == WALL)
      return false;
    if (pos.y < 0 || pos.y >= size 
      || pos.x < 0 || pos.x >= size)
      return false;
  }

  return true;
}

bool House::hasPipeArrived()
{
  yx pos = pipe.getPosition();

  switch (pipe.getState()) {
  case 1:
    return (pos.y == size - 1) && (pos.x == size - 2);
    break;
  case 2:
    return (pos.y == size - 2) && (pos.x == size - 2);
    break;
  case 3:
    return (pos.y == size - 2) && (pos.x == size - 1);
    break;
  }

  return false;
}

void House::getInput() 
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      cin >> map[i][j];
}
