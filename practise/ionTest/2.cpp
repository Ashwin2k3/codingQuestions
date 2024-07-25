#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Recursive helper function to calculate the minimum number of transactions
int minimizeTransactions(vector<int>& balances, int start) {
    // Find the first non-zero balance
    while (start < balances.size() && balances[start] == 0) {
        start++;
    }

    // Base case: If all balances are zero, no transactions are needed
    if (start == balances.size()) {
        return 0;
    }

    int minTransactions = INT_MAX;

    // Try settling the current balance with every other non-zero balance
    for (int i = start + 1; i < balances.size(); ++i) {
        if (balances[i] * balances[start] < 0) {
            // Choose to settle the `start` person with the `i` person
            balances[i] += balances[start];
            minTransactions = min(minTransactions, 1 + minimizeTransactions(balances, start + 1));
            // Backtrack to restore the original balances
            balances[i] -= balances[start];
        }
    }

    return minTransactions;
}

// Main function to calculate the minimum number of transactions required to clear all debts
int getMinTransactions(int n, vector<vector<int>> debts) {
    vector<int> netBalance(n, 0);

    // Compute net balance for each person
    for (const auto& debt : debts) {
        int from = debt[0];
        int to = debt[1];
        int amount = debt[2];

        netBalance[from] -= amount;
        netBalance[to] += amount;
    }

    // Filter out non-zero balances
    vector<int> balances;
    for (int balance : netBalance) {
        if (balance != 0) {
            balances.push_back(balance);
        }
    }

    // Start the recursion to minimize transactions
    return minimizeTransactions(balances, 0);
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

