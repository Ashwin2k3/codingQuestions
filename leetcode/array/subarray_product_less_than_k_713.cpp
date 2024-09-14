class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {

            int left = 0, right = 0 ;
            long long currentProd = 1 ;

            int cnt = 0;
            while(right < nums.size() ){
                currentProd *= nums[right];

                while(currentProd > k -1  and left <= right){
                    currentProd /= nums[left];
                    left ++ ;
                }

                if (currentProd <= k - 1) {
                    cnt += right - left + 1 ;
                }

                right++ ;

            }
            return cnt;
        }
};


