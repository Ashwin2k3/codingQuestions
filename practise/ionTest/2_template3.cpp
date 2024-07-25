#include <bits/stdc++.h>
using namespace std;


// Function to calculate the minimum number of transactions required to clear all debts
int getMinTransactions(int n, vector<vector<int>> debts) {

   }

int main() {
    // Define test cases
    vector<tuple<int, int, vector<vector<int>>>> testCases = {
        {3, 4, {{0, 1, 20}, {1, 0, 5}, {1, 2, 10}, {2, 0, 10}}},  // Expected output: 1
        {3, 0, {}},  // Expected output: 0
        {4, 4, {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 0, 10}}},  // Expected output: 0
        {4, 5, {{0, 1, 10}, {1, 2, 5}, {2, 3, 15}, {3, 0, 5}, {0, 2, 5}}},  // Expected output: 2
        {5, 6, {{0, 1, 15}, {1, 2, 20}, {2, 3, 5}, {3, 4, 10}, {4, 0, 10}, {2, 4, 5}}}  // Expected output: 3
    };

    // Run each test case
    for (int i = 0; i < testCases.size(); ++i) {
        int n = get<0>(testCases[i]);
        int m = get<1>(testCases[i]);
        vector<vector<int>> debts = get<2>(testCases[i]);
        
        int result = getMinTransactions(n, debts);
        
        // Print the results
        cout << "Test Case " << i + 1 << ": ";
        cout << "Expected: " << (i == 0 ? 1 : i == 1 ? 0 : i == 2 ? 0 : i == 3 ? 2 : 3) << ", ";
        cout << "Got: " << result;
        if (result == (i == 0 ? 1 : i == 1 ? 0 : i == 2 ? 0 : i == 3 ? 2 : 3)) {
            cout << " [PASS]" << endl;
        } else {
            cout << " [FAIL]" << endl;
        }
    }

    return 0;
}

