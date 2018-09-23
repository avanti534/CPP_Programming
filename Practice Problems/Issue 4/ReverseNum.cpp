#include <iostream>

int reverse(int n);
int reverse(int n) {
  int reverseNum = 0, rem;
  while (n != 0) {
    rem = n % 10; // 2
    reverseNum = reverseNum*10 + rem; // => 2
    n /= 10; // => 51
  }
  return reverseNum;
}

int main() {
  std::cout << reverse(512) << std::endl;

}
