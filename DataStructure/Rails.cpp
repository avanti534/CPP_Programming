// UVA 514
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

void canSolve(vector<int> coaches) {
	int N = coaches.size();
	int coachesIndex = 0;
	// First in, Last out
	// Can put directly into last index
	stack<int> cStack;
	// Use for loop for each (ordered) coach
	for (int i = 1; i <= N; i++){
		// Add the current element to the stack
		cStack.push(i);
		// Check if the current element is equal to the target value (coaches[coachesIndex])
		// Check all previous values as well
		while (!cStack.empty() && cStack.top() == coaches[coachesIndex]) {
			// If it is equal, remove that element and add to the coaches
			// Index again (one more solved element)
			cStack.pop();
			coachesIndex++;
		}
	}
	// See if we have completed all values of the vector
	if (coachesIndex == N) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}



}



int main() {
	FILE* file = fopen("input 5.txt", "r");
	// Number of coaches
	int N;
	vector<int> coaches;
	while (true) {
		// Read N numbers (from file)
		fscanf(file, "%d", &N);
		if (N == 0)
			break;
		// Clean coaches each time
		// Before adding new set
		while(true){
			coaches.clear();
			for (int i = 0; i < N; i++) {
				int x;
				fscanf(file, "%d", &x);
				if (x == 0)
					break;
				coaches.push_back(x);
			}
			if (coaches.empty())
				break;

			// TODO Solve here
			canSolve(coaches);
		}
	}
}
