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

    for (int i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        vector<vector<int>> debts = testCases[i].second;
        cout << "Test Case " << i + 1 << ": Minimum number of transactions: " << getMinTransactions(n, debts) << endl;
    }

    return 0;
}

