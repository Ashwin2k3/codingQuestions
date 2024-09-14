class Solution {
public:
    int getLucky(string s, int k) {
        string numStr = "";
        
        for (char c : s) {
            int pos = (c - 'a' + 1); 
            numStr += to_string(pos); 
        }

        while (k--) {
            int sum = 0;
            for (char c : numStr) {
                sum += (c - '0'); 
            }
            numStr = to_string(sum); 
        }
        
        return stoi(numStr);
    }
};

