#include <iostream>
#include <vector>
using namespace std;

void rotateAntiClockwise(vector<vector<int>>& matrix) {
    int N = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N / 2; i++) {
            swap(matrix[i][j], matrix[N - 1 - i][j]);
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    
    // Input the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    rotateAntiClockwise(matrix);

    // Output the rotated matrix
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

