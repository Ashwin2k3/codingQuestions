class Solution {
public:
    bool canJump(vector<int>& nums) {
        int j =0;
        for(int i=0;i<=j;i++){
            j = max(j,i+nums[i]);
            if(j>=nums.size()-1){
                return true;
            }
        }
        return false;
    }

};
