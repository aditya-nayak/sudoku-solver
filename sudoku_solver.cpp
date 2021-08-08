#include<bits/stdc++.h>
using namespace std;

const int N = 9;
int grid[N][N];

bool isValid(int row, int col, int number) {
    for (int i = 0; i < N; i++) {
        if ((grid[row][i] == number && i != col)
            || (grid[i][col] == number && i != row)) {
            return false;
        }
    }

    int temp1 = row / 3;
    int temp2 = col / 3;

    for (int i = temp1 * 3; i <= ((temp1+1) * 3) - 1; i++) {
        for (int j = temp2 * 3; j <= ((temp2+1) * 3) - 1; j++) {
            if (grid[i][j] == number && !(i == row && j == col)) {
                return false;
            }
        }
    }

    return true;
}
bool findUnassignedLocation(int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }

    return false;
}

void displayGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<grid[i][j]<<" ";
        }

        cout<<"\n";
    }
}

bool solver() {
    int row, col;

    if(!findUnassignedLocation(row, col)) {
        return true;
    } else {
        for (int i = 1; i < 10; i++) {
            if (isValid(row, col, i)) {
                grid[row][col] = i;

                if (solver()) {
                    return true;
                }

                grid[row][col] = 0;
            }
        }

        return false;
    }
}

int main() {
    cout<<"Input the unsolved Sudoku line-wise, with 0s in place of blank cells:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>grid[i][j];
        }
    }

    solver();
    cout<<"\n\n";
    displayGrid();

    return 0;
}
