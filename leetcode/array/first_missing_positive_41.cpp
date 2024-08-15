/*
   simplest appraoach 
   1) sort the array
   2) use 2 pointers and 


   0 1 2 
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s ;
        for(auto it : nums){
            s.insert(it);
        }
        for(int i=1;i<nums.size()+1;i++){
            if(!s.count(i)){
                return i;
            }
        }  
        return nums.size()+1;
    }
};


