class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string > v ;

        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j){
                    if (words[j].find(words[i]) != string::npos) {
                        v.push_back(words[i]);
                        break;
                    }
                }
                    
            }
        }

        return v ;
        
    }
};

