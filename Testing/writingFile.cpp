// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

void makeFile();

int main () {
  makeFile();
}

void makeFile() {
  ofstream myfile ("test.in");
  if (myfile.is_open()) {
    myfile << "4\n";
    myfile << "3\n";
    myfile.close();
  } else cout << "Unable to open file.\n";
}
