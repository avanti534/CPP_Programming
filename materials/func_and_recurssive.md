# Use of structure
```
typedef struct {
  double x, y;
} Point; // don't forget the semicolon

double dist(Point a, Point b){i
  // TODO here...
}
```

Ex1. Calc C(m,n) = n! / (m!(n-m)!)

Ex2. is_prime(int n)
```
int is_prime(int n){
  if(n <= 1) return 0;
  int m = floor(sqrt(n) + 0.5);
  for (int i = 2; i <= m; i++)
    if(n % i == 0)
      return 0;
  return 1;
}
```

# Funcs
## Parameter parsing
Error demo
```
void swap(int a, int b){
  int t = a;
  a = b;
  b = t;
}
```

Using pointers
```
void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

int main(){
  int a = 3, b = 4;
  swap(&a, &b);
}
```
Using reference
```
void swap(int &a, int &b){
  int t = a;
  a = b;
  b = t;
}
```

Calc sum of array
```
int sum(int *a, int n){
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i];
  return ans;
}

int main(){
  int a[] = {1, 2, 3, 4};
  printf("%d\n", sum(a, 4));
  printf("%d\n", sum(a+1, 3));
  return 0;
}
```

# Recurssion
```
include <stdio.h>

int f(int n ){
  return n == 0? 1: f(n-1) * n;
}
```

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=69
```
include <stdio.h>
define maxn 25
int n, k, m, a[maxn];

int go(int p, int d, int t){
  while(t --){
    do{
      p = (p+d+n-1)% n + 1;
    }while(a[p] == 0);
 }
 return p;
}

int main(){
  while(scanf(%d%d%d", &n, &k, &m) == 3 && n){
    for (int i = 1; i <= n; i++)
      a [i] = i;
    int left = n;
    int p1 = n; p2 = 1;
    while(left){
      p1 = go(p1, 1, k);
      p2 = go(p2, -1, m);
      printf("3d", p1);
      left--;
      if(p2 != p1){
        printf("%3d", p2);
        left--;
      }
      a[p1] = a[p2] = 0;
      if(left)
        printf(",");
    }
    printf("\n");
  }
  return 0;
}
```


