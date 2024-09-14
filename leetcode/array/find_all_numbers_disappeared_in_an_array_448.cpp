class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s ;
        vector<int> v;
        for(auto it : nums){
            s.insert(it);
        }
        for(int i=1 ;i<nums.size()+1 ;i++){
            if(!s.count(i)){
                v.push_back(i);
            }
        }

        return v ;
        
    }
};

