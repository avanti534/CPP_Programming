#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  string line;
  int num1;
  int num2;
  ofstream fileOut ("add.out");
  ifstream myfile ("add.in");
  myfile >> num1 >> num2;
  fileOut << num1 + num2 << endl;
}
