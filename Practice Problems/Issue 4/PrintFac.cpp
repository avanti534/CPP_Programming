#include <iostream>

int solve(int n);

int main() {
  std::cout << solve(20) << std::endl;
}

int solve(int n) {
  int sum;
  int cache=1;
  for (int i = 1; i <= n; i++) {
    int tmp = cache * i;
    sum += tmp;
    sum %= 1000000;
    cache = tmp;
    cache %= 1000000;
  }

  return sum;
}
