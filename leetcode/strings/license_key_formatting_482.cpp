class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string alpha = "";
        for(char c : s){
            if(c != '-'){
                alpha += toupper(c);

            }
        }
        int n = alpha.size();
        string res = "";

        int firstGroup = n % k;
        int idx = 0;

        if (firstGroup > 0) {
            res += alpha.substr(idx, firstGroup);
            idx += firstGroup;
            if (index < n) {
                res += '-';
            }
        }

        while (idx < n){
            res += alpha.substr(idx, k);
            index += ;
            if(idx < n){
                res += "-";
            }
        }

        return res ;
    }
};

