#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Main function to calculate the minimum number of transactions required to clear all debts
int getMinTransactions(int n, vector<vector<int>> debts) {

    }

int main() {
    vector<pair<int, vector<vector<int>>>> testCases = {
        {3, {{0, 1, 10}, {2, 0, 5}}},
        {3, {}},
        {2, {{0, 1, 20}}},
        {4, {{0, 1, 10}, {2, 3, 15}, {1, 3, 5}}},
        {5, {{0, 1, 10}, {1, 2, 5}, {2, 3, 15}, {3, 4, 7}, {4, 0, 8}}},
        {4, {{0, 1, 10}, {1, 0, 10}, {2, 3, 5}, {3, 2, 5}}}
    };

    vector<int> expectedResults = {
        2,  // Test Case 1
        0,  // Test Case 2
        1,  // Test Case 3
        2,  // Test Case 4
        3,  // Test Case 5
        0   // Test Case 6
    };

    for (int i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        vector<vector<int>> debts = testCases[i].second;
        int result = getMinTransactions(n, debts);
        cout << "Test Case " << i + 1 << ": ";
        cout << "Expected: " << expectedResults[i] << ", ";
        cout << "Got: " << result;
        if (result == expectedResults[i]) {
            cout << " [PASS]" << endl;
        } else {
            cout << " [FAIL]" << endl;
        }
    }

    return 0;
}

