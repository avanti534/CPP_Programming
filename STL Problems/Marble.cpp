// ID: UVA 10474
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

// Recieved marble number and number ("queries") to search for
void solve(vector<int> marbles, vector<int> queries){
  sort(marbles.begin(), marbles.end());
  // Search for the index of the querie
  for (int q : queries) {
    if (binary_search(marbles.begin(), marbles.end(), q)) {
      cout << "Case " << q << " found at index ";
      cout << lower_bound(marbles.begin(), marbles.end(), q) - marbles.begin() + 1 << endl;
    } else {
      cout << "Query not found" << endl;
    }
  }

}

int main() {
  FILE *file = fopen("input 3.txt", "r");
  int N, Q;
  while (true) {
    fscanf(file, "%d %d", &N, &Q);
    if (N == 0 && Q == 0)
      break;

    vector<int> marbles(N);
    vector<int> queries(Q);

    for(int i = 0; i < N; i++){
      fscanf(file, "%d", &marbles[i]);
    }

    for(int i = 0; i < Q; i++){
      fscanf(file, "%d", &queries[i]);
    }

    solve(marbles, queries);
  }
}
