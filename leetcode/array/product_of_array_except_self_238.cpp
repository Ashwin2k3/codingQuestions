/*
 brute force 
   class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        
        for(int i=0;i<nums.size();i++){
            int ans = 1;
            for(int j=0;j<nums.size();j++){
                if(j==i){
                    continue;
                }
                ans *= nums[j];
            }
            answer[i] = ans ;
        }
        return answer;
    }
};

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] =1 ;
        right[n-1] = 1 ;

        for(int i=1;i<n;i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i=n-2 ; i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i=0;i<n;i++){
            answer[i]= right[i] * left[i];

        }
        return answer;
        
};
