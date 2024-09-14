class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s ;
        vector<int> v ;
        for(auto it : nums){
            if(s.count(it)){
                v.push_back(it);
                continue ;
            }
            s.insert(it);
            
        }
        
        return v;
        
    }
};

