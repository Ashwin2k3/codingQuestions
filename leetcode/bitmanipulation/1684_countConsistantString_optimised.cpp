/*
   To achieve the best time complexity for solving the problem "Count the Number of Consistent Strings" using bit manipulation, you can take advantage of the small and fixed character set (lowercase English letters) and the distinct characters in the `allowed` string. The approach involves creating bitmasks for the allowed characters and each word, then comparing these bitmasks to count the consistent strings.

### Explanation:

1. **Create a Bitmask for Allowed Characters**:
   - Initialize `allowedMask` to 0.
   - For each character `c` in `allowed`, set the corresponding bit in `allowedMask` using `allowedMask |= (1 << (c - 'a'))`.
   - This operation takes \(O(1)\) time for each character since `allowed` can only have up to 26 distinct characters.

2. **Create and Check Bitmask for Each Word**:
   - For each word in `words`, initialize `wordMask` to 0.
   - For each character `c` in the word, set the corresponding bit in `wordMask` using `wordMask |= (1 << (c - 'a'))`.
   - Check if all bits set in `wordMask` are also set in `allowedMask` using `(wordMask & allowedMask) == wordMask`.
   - This check takes \(O(1)\) time for each word since words can have up to 10 characters.

3. **Counting Consistent Strings**:
   - Increment the counter `cnt` for each consistent word.

### Time Complexity:
- Creating the `allowedMask` takes \(O(allowed.length())\) time, which is \(O(26)\) in the worst case and effectively constant time.
- Checking each word involves creating a `wordMask` and performing a bitwise comparison, both of which take \(O(word.length())\) time per word, which is \(O(10)\) in the worst case and effectively constant time.
- Thus, the overall time complexity is \(O(words.length \times 10)\), which simplifies to \(O(n)\), where \(n\) is the number of words in the `words` array.

This approach ensures optimal performance given the problem constraints.
*/


#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedMask = 0;
        
        // Create bitmask for allowed characters
        for (char c : allowed) {
            allowedMask |= (1 << (c - 'a'));
        }
        
        int cnt = 0;
        
        // Check each word
        for (const auto& word : words) {
            int wordMask = 0;
            
            // Create bitmask for current word
            for (char c : word) {
                wordMask |= (1 << (c - 'a'));
            }
            
            // Check if wordMask is a subset of allowedMask
            if ((wordMask & allowedMask) == wordMask) {
                cnt++;
            }
        }
        
        return cnt;
    }
};

