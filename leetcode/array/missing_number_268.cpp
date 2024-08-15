class Solution {
public:
    int missingNumber(vector<int>& nums) {

        unordered_set<int> s ;
        for(auto it : nums){
            s.insert(it);
        }
        for(int i=0;i<nums.size()+1;i++){
            if(!s.count(i)){
                return i;
            }
        }
        return nums.size()+1;

    }
};

