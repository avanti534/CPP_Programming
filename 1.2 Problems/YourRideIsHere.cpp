/*
ID: spengo31
TASK: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s1;
    string s2;

    fin >> s1 >> s2;
    cout<< s1 << endl;
    cout<< s2 << endl;

    int product1 = 1;
    for (int i=0; i <s1.size(); ++i) {
      product1 *= s1[i] - 'A'+1;
      product1 %= 47;
    }
    int product2 = 1;
    for (int i=0; i<s2.size(); i++) {
      product2 *= s2[i] - 'A' + 1;
      product2 %= 47;
    }

    cout << (product1==product2?"GO":"STAY") << endl;
    fout << (product1==product2?"GO":"STAY") << endl;
    return 0;
}
