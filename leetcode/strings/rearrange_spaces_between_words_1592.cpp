class Solution {
public:
    string reorderSpaces(string text) {

        int cnt = 0;
        vector<string> v;

        string word = "";
        for(char c  : text){
            if(c == ' '){
                cnt ++ ;
                if(!word.empty()){
                    v.push_back(word);
                    word = "";
                }
            }
            else{
                word += c ;
            }
        }
        if (!word.empty()) {
            v.push_back(word);
        }

        int n = v.size();
        int spacesBetweenWords = n > 1 ? cnt / (n -1 ): 0;
        int extraSpace = n > 1 ? cnt %(n -1 ): cnt ;/* code */

        string res = "";
        for(int i=0;i<n;i++){
            res += v[i];
            if(i<n-1){
                res += string(spacesBetweenWords, ' ');
            }
        }

        result += string(extraSpace, ' ');

        return result ;
    }
};
