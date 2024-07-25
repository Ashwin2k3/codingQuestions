#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Function to compute minimum time to transition between servers
long getMinimumTime(vector<int> requestedServers, vector<int> transitionTime) {
    
    // write code here 
    }


int main() {
    // Example test cases
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{2, 3, 3, 1}, {3, 2, 1}}, // Test case 1
        {{1, 2, 3, 4}, {1, 2, 3, 4}}, // Test case 2
        {{1, 2, 1}, {2, 2}}, // Test case 3
        {{1, 3, 2, 4}, {4, 1, 2, 3}} // Test case 4
    };

    // Expected outputs for the test cases
    vector<long> expectedOutputs = {6, 4, 2, 6};

    // Running test cases
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> requestedServers = testCases[i].first;
        vector<int> transitionTime = testCases[i].second;
        
        long result = getMinimumTime(requestedServers, transitionTime);
        
        cout << "Test Case " << i + 1 << ": ";
        cout << "Expected: " << expectedOutputs[i] << ", ";
        cout << "Got: " << result;
        if (result == expectedOutputs[i]) {
            cout << " [PASS]" << endl;
        } else {
            cout << " [FAIL]" << endl;
        }
    }

    return 0;
}

