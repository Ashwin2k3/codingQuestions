class Solution {
public:
    string reformatNumber(string number) {
        stringstream ss(number);
        string temp ;
        vector<string> word;
        while(getline(ss,temp, ' ' or '-')){
            word.push_back(temp);
        }
        string s  ="";
        for(auto it : word){
            s += it ;
        }

        
    }
};
