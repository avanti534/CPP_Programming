#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

#define SIZE 26

map<char, int> letterCount(string str) {
  map<char, int> countMap;
  int n = str.size();
  int freq[SIZE];
  // Initialize all elements of freq to 0
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < n; i++) {
    // Char count
    freq[tolower(str[i]) - 'a']++;
  }

  for (int i = 0; i < SIZE; i++) {
    if (freq[i] > 0) {
      countMap.insert(pair<char, int> ('a'+i, freq[i]));
    }
  }

  // for (pair<char, int> n : countMap) {
  //   cout << n.first << n.second << endl;
  // }
  return countMap;
}

int main() {
  map<char, int> helloLetters = letterCount("hEllo");
  map<char, int> hello2Letters = letterCount("olleh");

  if (helloLetters == hello2Letters) {
    cout << "Works" << endl;
  } else {
    cout << "Does not work" << endl;
  }
  return 0;
}
