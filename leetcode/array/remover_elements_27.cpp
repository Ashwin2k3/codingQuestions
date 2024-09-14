class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        int n = nums.size();
    
    while (left < n) {
        if (nums[left] != val) {
            swap(nums[left], nums[right]);
            right++;
        }
        left++;
    }
    
    return right;
    }
};

