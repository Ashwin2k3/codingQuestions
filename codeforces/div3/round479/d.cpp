#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<long long, int> freq;

bool canConstructSequence(vector<long long>& nums, int n, vector<long long>& result) {
    for (auto num : nums) {
        freq[num]++;
    }
    
    for (auto num : nums) {
        vector<long long> temp;
        temp.push_back(num);
        freq[num]--;
        bool found = true;
        
        for (int i = 1; i < n; ++i) {
            long long next;
            if (num % 3 == 0 && freq[num / 3] > 0) {
                next = num / 3;
            } else if (freq[num * 2] > 0) {
                next = num * 2;
            } else {
                found = false;
                break;
            }
            
            temp.push_back(next);
            freq[next]--;
            num = next;
        }
        
        if (found) {
            result = temp;
            return true;
        }
        
        // Reset frequency count
        for (auto num : temp) {
            freq[num]++;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
    
    vector<long long> result;
    if (canConstructSequence(sequence, n, result)) {
        for (int i = 0; i < n; ++i) {
            cout << result[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}

