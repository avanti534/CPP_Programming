#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void decToBinary(int n, int **solution);

int solveButtons(int buttons[5][6]);
int solveButtons(int buttons[5][6]) {
  for (int i = 0; i < 64; i++) {
    int solution[5][6];
    int status[5][6];
    memcpy(status, buttons, sizeof(buttons));
    decToBinary(i, solution);
    // Initial first row (brute force)
    for (int indx = 0; indx < 6; indx++) {
      if (solution[0][indx] == 1) {
        clickButton(0, indx, status);
      }
    }
    // Solve for each row under first
    for (int xindx = 1; xindx < 5; xindx++) {
      // Solve for each button to fix any above values
      for (int indx = 0; indx < 6; indx++) {

        if (status[xindx-1][indx] == 1) {
          solution[xindx][indx] = 1;
          clickButton(xindx, indx, status);
        }
      }

    }
    bool works = true;
    for (int y = 0; y < 6; y++) {
      if (status[5][y] == 1) {
        works = false;
        break;
      }
    }
    cout << "Solution works!" << endl;
  }
  return 0;
}

void clickButton(int x, int y, int ** status) {
  status[x][y] ^= 1;
  // up 1, down 1, left 1, right, 1
  if (y != 0) {
    // Make sure value is not at the top
    status[x][y-1] ^= 1;
  }
  if (y != 4) {
    // Make sure value is not on bottom
    status[x][y+1] ^= 1;
  }
  if (x!= 0) {
    // Make sure value is not left
    status[x-1][y] ^= 1;
  }
  if (x != 5) {
    // Make sure value is not right
    status[x+1][y] ^= 1;
  }
}

// function to convert decimal to binary
void decToBinary(int n, int **solution)
{
    int binaryNum[6];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    // x : y
    solution[0][0] = binaryNum[5]
    solution[0][1] = binaryNum[4];
    solution[0][2] = binaryNum[3];
    solution[0][3] = binaryNum[2];
    solution[0][4] = binaryNum[1];
    solution[0][5] = binaryNum[0];
}

int main() {
  int buttons[5][6];
  int n;
  ifstream fin ("buttons.in");
  fin >> n;
  while (n--) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 6; j++) {
        fin >> buttons[i][j];
        solveButtons(buttons);
      }
    }
  }
}
