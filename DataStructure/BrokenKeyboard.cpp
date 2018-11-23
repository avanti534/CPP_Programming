#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void solveLine(string line) {
	cout << line << endl;
}

int main() {
	FILE* file = fopen("input 6.txt", "r");
	// Number of coaches
	char x[100000];
	while (fgets(x, 100000, file) != NULL) {
		string line(x);
		solveLine(line);
	}
}


// fscanf format words/ints/
