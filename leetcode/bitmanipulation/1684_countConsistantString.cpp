#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        int cnt = 0;
        
        // Insert allowed characters into the set
        for (char c : allowed) {
            s.insert(c);
        }
        
        // Check each word
        for (const auto& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (s.find(c) == s.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                cnt++;
            }
        }
        
        return cnt;
    }
};

