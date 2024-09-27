#include <iostream>
using namespace std;

int main() {
    // Read the 3x3 matrix
    char grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    // Check for symmetry with respect to the central button (grid[1][1])
    if (grid[0][0] == grid[2][2] &&  // (1, 9) -> grid[0][0] and grid[2][2]
        grid[0][1] == grid[2][1] &&  // (2, 8) -> grid[0][1] and grid[2][1]
        grid[0][2] == grid[2][0] &&  // (3, 7) -> grid[0][2] and grid[2][0]
        grid[1][0] == grid[1][2]) {   // (4, 6) -> grid[1][0] and grid[1][2]
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

