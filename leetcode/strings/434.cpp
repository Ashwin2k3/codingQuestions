#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        vector<string> token;
        string temp;
        while(getline(ss, temp, ' ')){
            if (!temp.empty()) { 
                token.push_back(temp);
            }
        } 

        cout << token.size() << endl;
        return token.size(); 
    }
};

