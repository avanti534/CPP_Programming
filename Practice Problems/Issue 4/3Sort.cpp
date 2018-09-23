#include <iostream>

int sort(int p[], int n);
int sort(int p[], int n) {

  for (int i = 1; i < n; i++) {
    for (int j = i-1; j >= 0; j--) {
      if (p[j] > p[j+1]) {
        int tmp = p[j];
        p[j] = p[j+1];
        p[j+1] = tmp;
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << p[i] << std::endl;
  }
  return 0;

}



int main() {
  int p[3] = {3,4,1};
  sort(p, sizeof(p)/sizeof(int));
}
