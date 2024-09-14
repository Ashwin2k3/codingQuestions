class Solution {
public:
    int lengthOfLastWord(string s) {
       int left = s.size() -1 ;
       int cnt = 0;
       while(left >= 0 and s[left] == ' '){
        left --;
       }
       while(left>=0 and s[left] != ' '){
        cnt ++ ;
        left--;
       }
       return cnt;
       
    }
};
;
