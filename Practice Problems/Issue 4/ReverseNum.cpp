#include <iostream>

int reverse(int n);
int reverse(int n) {
  int reverseNum = 0, rem;
  while (n != 0) {
    rem = n % 10; // 5
    reverseNum = reverseNum*10 + rem; // => 215
    n /= 10; // => 0
  }
  return reverseNum;
}

int main() {
  std::cout << reverse(512) << std::endl;

}
