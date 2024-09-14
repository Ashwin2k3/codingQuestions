class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string result = "";
        int count = 0;

        for(int i=s.size()-1 ; i>= 0;i--){
            if (s[i] != '-') {

                if(count  == k){
                    result += '-';
                    count = 0;
                }
                result += toupper(s[i]);
                count ++ ;
            }

        }

        reverse(result.begin(), result.end());

        return result ;
    }
};
