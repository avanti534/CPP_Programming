#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve(vector<string> names) {
	sort(names.begin(), names.end());
	int longestLength = 0;
	// Find the longest length
	for (string s : names) {
		if (s.length() > longestLength) {
			longestLength = s.length();
		}
	}
	// Defined in problem document
	// Cols
	int cNum = 60 / (longestLength + 2);
	// Rows
	int rNum = names.size() / cNum;
	if (names.size() % cNum != 0) {
		// Add one row if num is not divisable from Cols
		rNum ++;
	}
	vector<vector<string>> list;
	// For each row
	// Only init
	for (int i = 0; i < rNum; i++) {
		// Fill the col
		vector<string> s (cNum);
		list.push_back(s);
	}
	int currentIndex = 0;
	for (int c = 0; c < cNum; c++) {
		for (int r = 0; r < rNum; r++) {
			list[r][c] = names[currentIndex];
			currentIndex++;
			if (currentIndex >= names.size()) {
				break;
			}
		}
	}

	// Printing
	// Print 60 -
	cout << string(60, '-') << endl;
	for (int r = 0; r < rNum; r++) {
		for (int c = 0; c < cNum; c++) {
			cout << list[r][c] << string((longestLength+2) - list[r][c].length(), ' ');
		}
		cout << endl;
	}
}

int main() {
  FILE *file = fopen("input 4.txt", "r");
  int n;
  vector<string> names;

  while (true) {
    if (fscanf(file, "%d", &n) != 1) {
      break;1
    }
    names.clear();
    for (int i = 0; i < n; i++) {
      char x[61];
      fscanf(file, "%61s", x);
      names.push_back(x);
    }
    solve(names);
  }
}
