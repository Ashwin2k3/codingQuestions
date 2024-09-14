class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int res = 0;
            int gap = INT_MAX;

            for(int i=0;i<nums.size() - 2 ;i++){
                int li = i+ 1 ;
                int ri = nums.size() -1 ;

                while(li < ri){
                    int sum = nums[i] + nums[li] + nums[ri];
                    int newgap = abs(target - sum);
                    if (sum < target) {
                        if (newgap < gap ){
                            gap = min(gap , newgap);
                            res = sum;
                        }
                        li++ ;
                    }
                    else if( sum > target ){
                        if(newgap < gap){
                            gap = min(gap , newgap);
                            res = sum;
                        }
                        ri--;
                    }
                    else{
                        return sum;
                    }
                }
            }
            return res;
        }
};


