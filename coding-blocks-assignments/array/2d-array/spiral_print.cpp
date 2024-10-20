#include <iostream>
#include <vector>
using namespace std;

void printSpiralAntiClockwise(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Print left column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][left]<<", ";
        }
        left++;

        // Print bottom row
        for (int i = left; i <= right; i++) {
            cout << matrix[bottom][i]<< ", ";
        }
        bottom--;

        // Print right column
        for (int i = bottom; i >= top; i--) {
            cout << matrix[i][right]<<", ";
        }
        right--;

        // Print top row
        for (int i = right; i >= left; i--) {
            cout << matrix[top][i]<<", ";
        }
        top++;

        // If more elements to be printed, print comma separator
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    // Input matrix elements
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print matrix in anti-clockwise spiral form
    printSpiralAntiClockwise(matrix);
    cout << "END\n"; // Print "END" at the end of output

    return 0;
}


