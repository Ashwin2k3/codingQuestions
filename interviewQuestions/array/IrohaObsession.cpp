#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to check if a number contains any disliked digits
bool containsDislikedDigits(int number, const set<int>& dislikedDigits) {
    while (number > 0) {
        if (dislikedDigits.find(number % 10) != dislikedDigits.end()) {
            return true;
        }
        number /= 10;
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    set<int> dislikedDigits;
    for (int i = 0; i < K; ++i) {
        int digit;
        cin >> digit;
        dislikedDigits.insert(digit);
    }

    // Start checking from N upwards until we find a valid number
    int currentNumber = N;
    while (containsDislikedDigits(currentNumber, dislikedDigits)) {
        ++currentNumber;
    }

    cout << currentNumber << endl;

    return 0;
}

