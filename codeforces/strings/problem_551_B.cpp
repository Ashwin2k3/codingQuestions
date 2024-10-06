#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    // Frequency array for the characters in 'a'
    vector<int> freq(26, 0);
    for (char ch : a) {
        freq[ch - 'a']++;
    }

    // Function to calculate how many times we can form string x from the freq array
    auto canForm = [&](const string &x) {
        int cnt = 1e9; // Set to a large number initially
        vector<int> needed(26, 0); // Frequency of characters needed for 'x'
        for (char ch : x) {
            needed[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (needed[i] > 0) {
                cnt = min(cnt, freq[i] / needed[i]); // How many times we can form 'x'
            }
        }
        return cnt;
    };

    // Calculate maximum number of `b` and `c` we can form
    int maxB = canForm(b);
    int maxC = canForm(c);

    int bestB = 0, bestC = 0;
    int maxCombined = 0;

    // Try different counts of `b` and `c` to maximize the total substrings
    for (int i = 0; i <= maxB; i++) {
        vector<int> tempFreq = freq; // Temporary frequency for this configuration
        // Decrease for `i` occurrences of `b`
        for (char ch : b) {
            tempFreq[ch - 'a'] -= i;
        }

        // Check how many `c` we can form after using `i` occurrences of `b`
        int possibleC = 1e9;
        vector<int> neededC(26, 0);
        for (char ch : c) {
            neededC[ch - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (neededC[j] > 0) {
                possibleC = min(possibleC, tempFreq[j] / neededC[j]);
            }
        }

        // Update the best configuration of `b` and `c`
        if (i + possibleC > maxCombined) {
            maxCombined = i + possibleC;
            bestB = i;
            bestC = possibleC;
        }
    }

    // Now, we have the optimal number of `b` and `c` to use (bestB and bestC)
    // Construct the result string
    string result = "";

    // Use bestB occurrences of `b`
    for (int i = 0; i < bestB; i++) {
        result += b;
        for (char ch : b) {
            freq[ch - 'a']--;
        }
    }

    // Use bestC occurrences of `c`
    for (int i = 0; i < bestC; i++) {
        result += c;
        for (char ch : c) {
            freq[ch - 'a']--;
        }
    }

    // Append remaining characters in any order
    for (int i = 0; i < 26; i++) {
        result += string(freq[i], 'a' + i);
    }

    // Output the result
    cout << result << endl;

    return 0;
}

