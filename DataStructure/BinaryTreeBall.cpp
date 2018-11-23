// UVA : 679
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	// Input
	int D, I; // D = Depth I = Num of Balls
	cout << "Input D: " << endl;
	cin >> D;
	cout << "Input I: " << endl;
	cin >> I;
	cout << endl;

	// Use a bool array as a tree
	bool BallTree[int(pow(2,D))]; // You can use an array as a complete binary tree
	memset(BallTree, false, sizeof BallTree); // Set all values in the tree to false
	// Test
	// for (bool c : BallTree) {
	// 	cout << c << endl;
	// }

	int cursor = 1; // location of the Ball
	for (int indx = 0; indx < I; indx++) {
		cursor = 1;
		for (int i = 1; i <= D-1; i++){ // if D = 4. pass 3 more times
			if (BallTree[cursor]){ // Right child
				BallTree[cursor] = !BallTree[cursor];
				cursor = 2 * cursor + 1;
			}
			else {// Left child
				// Change the value before you change the cursor
				BallTree[cursor] = !BallTree[cursor];
				cursor = 2 * cursor;
			}


		}
	}

	// Output the final cursor
	cout << "Final cursor: " << cursor << endl;

}
