class Solution {
public:
    string reverseVowels(string s) {
        int start = 0;
        int e = s.size() - 1 ;

        while (start<e) {   
            if(!isVowel(s[start])){
                start ++;
            }
            else if (!isVowel(s[e])) {
                e--;
            }
            else if (isVowel(s[e]) and isVowel(s[start])) {
                char temp ;
                temp = s[start];
                s[start] = s[e];
                s[e] = temp;
                start++;
                e--;
            }
        }

        return s ;
        
    }
    bool isVowel(char c){
        if(c =='a' or c == 'e' or c== 'i' or c == 'o' or c=='u' or c =='A' or c == 'E' or c =='I' or c=='O' or c=='U'){
            return true ;
        }
        else{
            return false;
        }
    }
};
