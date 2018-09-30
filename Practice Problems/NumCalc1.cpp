#include <iostream>

int main() {
  double sum = 1.0;
  int div = 2;
  for (int i = 0; i < 100; i++) {
    sum += (1.0/div);
    div *= 2;
    std::cout << sum << std::endl;
  }
  std::cout << sum << std::endl;
}
