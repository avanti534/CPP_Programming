// ID: UVA 156

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
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
  vector<string> words;

  FILE *file = fopen("input 2.txt", "r");
  char x[1024]; // tmp container for the scanner
  while (true){
    fscanf(file, "%1023s", x); // assuming reading 1023 chars at max. Reading word by word
    if (x[0] == '#')
      break;
    words.push_back(x);
  }

  vector<map<char, int>> maps;
  for (string n : words) {
    // Map
    map<char, int> tmpMap = letterCount(n);
    maps.push_back(tmpMap);
  }

  for (int i = 0; i < maps.size(); i++) {
    bool signal = false; // no repeated map
    for (int j = 0; j < maps.size(); j++) {
      if (i != j && maps[i] == maps[j]) {
        signal = true;
      }
    }
    if (!signal) {
      cout << words[i] << endl;
    }
  }

  return 0;
}
