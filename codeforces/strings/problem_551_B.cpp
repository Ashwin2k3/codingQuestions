#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


int countPossible(const string &x, vector<int> &freq) {
    vector<int> tempFreq = freq;  
    int count = 0;
    
    while (true) {
        bool canForm = true;
        for (char ch : x) {
            if (tempFreq[ch - 'a'] == 0) {
                canForm = false;
                break;
            }
            tempFreq[ch - 'a']--;
        }
        if (canForm)
            count++;
        else
            break;
    }
    return count;
}


string constructResult(string &a, string &b, string &c) {
    
    vector<int> freq(26, 0);
    for (char ch : a)
        freq[ch - 'a']++;
    
    
    int maxB = countPossible(b, freq);
    int maxC = countPossible(c, freq);
    
    
    vector<int> finalFreq = freq;  
    string result = "";
    
    
    while (countPossible(b, finalFreq) > 0) {
        result += b;
        for (char ch : b)
            finalFreq[ch - 'a']--;
    }

    
    while (countPossible(c, finalFreq) > 0) {
        result += c;
        for (char ch : c)
            finalFreq[ch - 'a']--;
    }

    
    for (int i = 0; i < 26; i++) {
        result += string(finalFreq[i], 'a' + i);
    }

    return result;
}

int main() {
    
    string a, b, c;
    cin >> a >> b >> c;

    
    string result = constructResult(a, b, c);

    
    cout << result << endl;

    return 0;
}

