#include <iostream>
#include <cmath>

int main() {
  double pi = 0.0;
  int div = 1;
  int step = 0;
  double small = 0;
  do {
    small = std::pow(-1, step) * (2 * step + 1);
    pi += 1.0/small;
    step++;
    std::cout << pi << step << std::endl;
  } while (std::fabs(1.0/small) > 1e-6);
  pi *= 4;
  std::cout << pi << std::endl;
}
