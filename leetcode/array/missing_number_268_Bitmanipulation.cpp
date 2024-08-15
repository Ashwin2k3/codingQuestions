class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int xorTilln = 0;
        for(int i =  0 ;i<=nums.size();i++){
            xorTilln ^= i;
        }
        for(auto it : nums){
            xorTilln ^= it;
        }
        return xorTilln;

     }
};
