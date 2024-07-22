#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> longestConsecutiveSubsequence(vector<int>& nums) {
    if (nums.empty()) {
        return {0, {}};
    }
    
    // Sort the array
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    int max_length = 1, current_length = 1, start_index = 0;
    
    // Find the longest consecutive subsequence
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            ++current_length;
        } else if (nums[i] != nums[i - 1]) {
            if (current_length > max_length) {
                max_length = current_length;
                start_index = i - current_length;
            }
            current_length = 1;
        }
    }
    
    // Check the last sequence
    if (current_length > max_length) {
        max_length = current_length;
        start_index = n - current_length;
    }
    
    // Prepare result indices
    vector<int> result_indices(max_length);
    for (int i = 0; i < max_length; ++i) {
        result_indices[i] = nums[start_index + i];
    }
    
    return {max_length, result_indices};
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    auto result = longestConsecutiveSubsequence(nums);
    cout << result.first << endl; // max_length
    for (int i = 0; i < result.first; ++i) {
        cout << result.second[i];
        if (i < result.first - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}

