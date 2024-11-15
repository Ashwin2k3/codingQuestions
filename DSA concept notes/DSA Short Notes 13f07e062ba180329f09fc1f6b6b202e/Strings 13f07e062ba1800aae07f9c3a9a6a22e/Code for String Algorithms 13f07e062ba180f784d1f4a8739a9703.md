# Code for String Algorithms

Here are implementations for some of the key string algorithms commonly asked in interviews:

### 1. **Naive String Matching Algorithm**

```cpp
#include <iostream>
#include <string>
using namespace std;

void naiveSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    naiveSearch(text, pattern);
    return 0;
}

```

### 2. **Knuth-Morris-Pratt (KMP) Algorithm**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPSArray(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearch(string text, string pattern) {
    vector<int> lps = computeLPSArray(pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    KMPSearch(text, pattern);
    return 0;
}

```

### 3. **Longest Palindromic Substring (Expanding Around Center)**

```cpp
#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    string longest = "";
    for (int i = 0; i < s.length(); i++) {
        string odd = expandAroundCenter(s, i, i);
        string even = expandAroundCenter(s, i, i + 1);

        if (odd.length() > longest.length()) {
            longest = odd;
        }
        if (even.length() > longest.length()) {
            longest = even;
        }
    }
    return longest;
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}

```

### 4. **Longest Common Subsequence (LCS)**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << "Length of Longest Common Subsequence: " << LCS(X, Y) << endl;
    return 0;
}

```

### 5. **Edit Distance (Levenshtein Distance)**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1 = "sitting";
    string str2 = "kitten";
    cout << "Edit Distance: " << editDistance(str1, str2) << endl;
    return 0;
}

```

### 6. **Check if Two Strings are Anagrams**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";
    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}

```

### 7. **Find All Anagrams in a String**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length()) return result;

    unordered_map<char, int> pCount, sCount;
    for (char c : p) pCount[c]++;

    for (int i = 0; i < p.length(); i++) sCount[s[i]]++;

    if (pCount == sCount) result.push_back(0);

    for (int i = p.length(); i < s.length(); i++) {
        sCount[s[i]]++;
        sCount[s[i - p.length()]]--;

        if (sCount[s[i - p.length()]] == 0) sCount.erase(s[i - p.length()]);

        if (pCount == sCount) result.push_back(i - p.length() + 1);
    }
    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

```

---

### 8. **Substring Search using Rabin-Karp Algorithm**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int d = 256; // Number of characters in the input alphabet
const int q = 101; // A prime number

void RabinKarpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;
    int p = 0;  // Hash value for pattern
    int t = 0;  // Hash value for text
    int h = 1;  // d^(m-1) % q

    // Precompute h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Compute hash value of pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // If the hash values match, check for exact match
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) break;
            }
            if (j == m) cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEKS";
    RabinKarpSearch(text, pattern);
    return 0;
}

```

### 9. **Z-Algorithm**

The Z algorithm computes the Z-array, which represents the longest prefix of the string that is also a suffix starting at each position in the string.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> ZAlgorithm(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s = "aaacaaaa";
    vector<int> z = ZAlgorithm(s);

    cout << "Z-array: ";
    for (int i : z) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

```

### 10. **String Compression (Run-Length Encoding)**

```cpp
#include <iostream>
#include <string>
using namespace std;

string runLengthEncoding(string s) {
    string result = "";
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && s[i] == s[i + 1]) {
            count++;
            i++;
        }
        result += s[i] + to_string(count);
    }

    return result;
}

int main() {
    string s = "aaabbbccdaa";
    cout << "Encoded string: " << runLengthEncoding(s) << endl;
    return 0;
}

```

### 11. **Find the Longest Common Prefix**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < strs[i].length() && j < prefix.length() && strs[i][j] == prefix[j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix == "") return "";
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}

```

### 12. **String Reverse Words (Reverse each word in the string)**

```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word, result = "";

    while (ss >> word) {
        if (result != "") result = word + " " + result;
        else result = word;
    }

    return result;
}

int main() {
    string s = "the sky is blue";
    cout << "Reversed words: " << reverseWords(s) << endl;
    return 0;
}

```

### 13. **Check if a String is a Valid Parentheses String**

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "{[()]}";
    if (isValid(s)) cout << "Valid Parentheses" << endl;
    else cout << "Invalid Parentheses" << endl;
    return 0;
}

```

### 14. **Find the Longest Substring Without Repeating Characters**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringWithoutRepeating(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0, start = 0;

    for (int end = 0; end < s.length(); end++) {
        if (charIndex.find(s[end]) != charIndex.end()) {
            start = max(start, charIndex[s[end]] + 1);
        }
        charIndex[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest Substring Without Repeating Characters: " << longestSubstringWithoutRepeating(s) << endl;
    return 0;
}

```

### 15. **Palindrome Partitioning**

Given a string `s`, partition it such that every substring of the partition is a palindrome. Return all possible palindrome partitioning.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void partitionHelper(string s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(s, 0, current, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);

    for (const auto& partition : result) {
        for (const auto& word : partition) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}

```

---

### 16. **Anagram Check**

To check if two strings are anagrams of each other (i.e., they contain the same characters with the same frequencies, but potentially in different orders).

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    if (areAnagrams(s1, s2)) {
        cout << "Strings are anagrams!" << endl;
    } else {
        cout << "Strings are not anagrams!" << endl;
    }

    return 0;
}

```

### 17. **Find All Permutations of a String**

Generate all permutations of a string using backtracking.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permute(string s, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r, result);
            swap(s[l], s[i]); // backtrack
        }
    }
}

vector<string> getPermutations(string s) {
    vector<string> result;
    permute(s, 0, s.length() - 1, result);
    return result;
}

int main() {
    string s = "abc";
    vector<string> result = getPermutations(s);

    for (const string& perm : result) {
        cout << perm << endl;
    }

    return 0;
}

```

### 18. **Find Substrings of a String**

Find all substrings of a string (non-contiguous substrings).

```cpp
#include <iostream>
#include <string>
using namespace std;

void findSubstrings(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}

int main() {
    string s = "abc";
    findSubstrings(s);
    return 0;
}

```

### 19. **Longest Palindromic Substring**

Find the longest palindromic substring in a given string.

```cpp
#include <iostream>
#include <string>
using namespace std;

string expandFromCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.length() < 1) return "";

    string longest;
    for (int i = 0; i < s.length(); i++) {
        string odd = expandFromCenter(s, i, i);
        string even = expandFromCenter(s, i, i + 1);

        if (odd.length() > longest.length()) longest = odd;
        if (even.length() > longest.length()) longest = even;
    }

    return longest;
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}

```

### 20. **Count and Say Sequence**

The "count-and-say" sequence is a series of strings where each term is generated by describing the previous term. The sequence begins with "1", and each subsequent term describes the previous one.

```cpp
#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    string result = "1";

    for (int i = 2; i <= n; i++) {
        string temp = "";
        int count = 1;

        for (int j = 1; j < result.length(); j++) {
            if (result[j] == result[j - 1]) {
                count++;
            } else {
                temp += to_string(count) + result[j - 1];
                count = 1;
            }
        }
        temp += to_string(count) + result[result.length() - 1];
        result = temp;
    }

    return result;
}

int main() {
    int n = 5;
    cout << "Count and Say Sequence for " << n << ": " << countAndSay(n) << endl;
    return 0;
}

```

### 21. **Wildcard Matching**

Implement wildcard pattern matching with support for `?` (matches any single character) and `*` (matches any sequence of characters, including the empty sequence).

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s = "adceb", p = "*a*b";
    if (isMatch(s, p)) {
        cout << "Pattern matches!" << endl;
    } else {
        cout << "Pattern doesn't match!" << endl;
    }
    return 0;
}

```

### 22. **KMP (Knuth-Morris-Pratt) String Matching Algorithm**

This algorithm is used for finding a pattern in a string efficiently by preprocessing the pattern.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPSArray(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}

```

### 23. **Minimum Window Substring**

Given two strings `S` and `T`, find the minimum window in `S` which contains all characters of `T`.

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string S, string T) {
    unordered_map<char, int> charCountT, charCountS;
    for (char c : T) charCountT[c]++;

    int left = 0, right = 0, minLen = INT_MAX, start = 0;
    int required = charCountT.size(), formed = 0;

    while (right < S.length()) {
        char rightChar = S[right];
        charCountS[rightChar]++;

        if (charCountT.count(rightChar) && charCountS[rightChar] == charCountT[rightChar]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char

 leftChar = S[left];
            charCountS[leftChar]--;
            if (charCountT.count(leftChar) && charCountS[leftChar] < charCountT[leftChar]) {
                formed--;
            }
            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : S.substr(start, minLen);
}

int main() {
    string S = "ADOBECODEBANC", T = "ABC";
    cout << "Minimum Window Substring: " << minWindow(S, T) << endl;
    return 0;
}

```

### 24. **Z-Algorithm (Pattern Matching)**

The Z-algorithm computes an array `Z` for a string where `Z[i]` represents the longest substring starting from `i` that matches the prefix of the string.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> ZAlgorithm(string s) {
    int n = s.length();
    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }

        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
}

int main() {
    string s = "aabxaabxca";
    vector<int> Z = ZAlgorithm(s);

    for (int z : Z) {
        cout << z << " ";
    }
    cout << endl;

    return 0;
}

```

### 25. **Rabin-Karp String Matching Algorithm**

This is a string searching algorithm that uses hashing to find an exact match of a pattern within a text.

```cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int d = 256;  // number of characters in the input alphabet
    int q = 101;  // prime number

    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    int p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    rabinKarp(text, pattern);

    return 0;
}

```

### 26. **Boyer-Moore String Matching Algorithm**

An efficient algorithm for string searching, which shifts the pattern based on the mismatch.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> badCharHeuristic(string pattern) {
    unordered_map<char, int> badChar;
    for (int i = 0; i < pattern.length(); i++) {
        badChar[pattern[i]] = i;
    }
    return badChar;
}

void boyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    unordered_map<char, int> badChar = badCharHeuristic(pattern);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCDABCABC";
    string pattern = "ABC";
    boyerMooreSearch(text, pattern);

    return 0;
}

```

### 27. **Longest Common Prefix (LCP)**

Find the longest common prefix string amongst an array of strings.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }

    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}

```

### 28. **Substring Search (Naive)**

A brute force way of finding a pattern in a string by checking each substring.

```cpp
#include <iostream>
#include <string>
using namespace std;

void naiveSubstringSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ABCABCABAB";
    string pattern = "ABC";
    naiveSubstringSearch(text, pattern);

    return 0;
}

```

### 29. **Find All Occurrences of a Substring**

This is another way of finding all occurrences of a substring within a larger string.

```cpp
#include <iostream>
#include <string>
using namespace std;

void findAllOccurrences(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        if (text.substr(i, m) == pattern) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ABABABAB";
    string pattern = "AB";
    findAllOccurrences(text, pattern);

    return 0;
}

```

### 30. **Levenshtein Distance (Edit Distance)**

The minimum number of operations required to convert one string to another (insert, delete, replace).

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int levenshteinDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    string str1 = "kitten";
    string str2 = "sitting";
    cout << "Levenshtein Distance: " << levenshteinDistance(str1, str2) << endl;
    return 0;
}

```

---

These are the remaining key string algorithms with their C++ implementations. They cover a broad range of string manipulation techniques that are often asked in interviews. Let me know if you need more details on any specific algorithm!