#include <stdio.h>
#include <iostream>

int main(){
  int p[4];
  p[0] = 0;
  p[1] = 1;
  p[2] = 2;
  p[3] = 3;
  std::cout << p[2] << std::endl;


  int p[4] = {0,1,2,3};
  int zeros[10] = {};
  int q[] = {1,2,3,4,5};

  int *a = new int[10]; // dynamic alloc

  delete a;

  return 0;
}
