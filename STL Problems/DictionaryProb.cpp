// ID: UVA 10815

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

// Split the words of a string from ' ' (space)
vector<string> splitString(string input) {
  string word;
  vector<string> words;

  stringstream ss(input);
  while (ss >> word) {
    words.push_back(word);
  }

  return words;
}

int main() {
  // Files
  string path = "input.txt";
  ifstream myfile(path);

  set<string> s;
  string line;
  vector<string> words;
  if (myfile.is_open()) {
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        for (int i = 0; i < line.length(); i++) {
          if (!isalpha(line[i])) {
            // Remove non-alpha characters: ","
            line[i] = ' ';
          } else {
            // Convert to lower: 'A' -> 'a'
            line[i] = tolower(line[i]);
          }
        }

        words = splitString(line);

        for (string word : words) {
          s.insert(word);
        }
      }
      myfile.close();
    }
  }

  for (string word : s) {
    cout << word << endl;
  }
  return 0;
}
