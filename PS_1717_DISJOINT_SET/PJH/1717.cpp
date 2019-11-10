#include <cstdio>

using namespace std;

int find(int id[], int i) {
  if (i == id[i])
    return i;
  return id[i] = find(id, id[i]);
}

void set_union(int id[], int a, int b) {
  int A = find(id, a);
  int B = find(id, b);
  if (B < A)
    id[A] = B;
  else 
    id[B] = A;
}

bool connected(int id[], int a, int b) {
  return find(id, a) == find(id, b);
} 

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int id[n + 1];
  for (int i = 1; i <= n; i++)
    id[i] = i;
  
  while (m--){
    int op, a, b;
    scanf("%d %d %d", &op, &a, &b);
    
    switch (op) {
    case 0:
      set_union(id, a, b);
      break;
    case 1:
      if(connected(id, a, b))
        printf("YES\n");
      else
        printf("NO\n");
      break;
    }
  }

  return 0;
}