#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to simulate the program for a segment of the sequence
vector<int> execute_program_segment(string segment) {
    int CP = 0;  // Current Pointer (start at the leftmost character)
    int DP = 1;  // Direction Pointer: 1 for right, -1 for left
    vector<int> count(10, 0);  // Count array for digits 0-9
    
    while (CP >= 0 && CP < segment.size()) {
        if (isdigit(segment[CP])) {
            // If it's a digit
            int digit = segment[CP] - '0';
            count[digit]++;  // Increment the count of this digit

            if (digit > 0) {
                // Decrease the digit in the segment
                segment[CP] = (digit - 1) + '0';
                CP += DP;
            } else {
                // Remove the digit if it's zero
                segment.erase(segment.begin() + CP);
                // If moving left and CP is not the first element, step back
                if (DP == -1 && CP > 0) {
                    CP--;
                }
            }
        } else if (segment[CP] == '<') {
            // If it's a '<', change direction to left
            DP = -1;
            CP += DP;
            // Remove the direction signs if they follow each other
            if (CP >= 0 && CP < segment.size() && (segment[CP] == '<' || segment[CP] == '>')) {
                segment.erase(segment.begin() + CP + (DP == 1 ? 1 : 0));
            }
        } else if (segment[CP] == '>') {
            // If it's a '>', change direction to right
            DP = 1;
            CP += DP;
            // Remove the direction signs if they follow each other
            if (CP < segment.size() && (segment[CP] == '<' || segment[CP] == '>')) {
                segment.erase(segment.begin() + CP + (DP == 1 ? -1 : 0));
            }
        }
    }

    return count;
}

int main() {
    int n, q;
    cin >> n >> q;  // Length of the sequence and number of queries

    string s;
    cin >> s;  // The sequence of "<", ">" and digits

    while (q--) {
        int l, r;
        cin >> l >> r;

        // Extract the subsequence from l to r (1-based index)
        string segment = s.substr(l - 1, r - l + 1);

        // Simulate the program for this segment
        vector<int> result = execute_program_segment(segment);

        // Output the result (count of each digit 0 to 9)
        for (int i = 0; i < 10; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

