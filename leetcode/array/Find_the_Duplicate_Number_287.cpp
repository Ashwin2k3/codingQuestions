class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Count how many numbers are less than or equal to mid
            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            // If count is greater than mid, duplicate is in [low, mid]
            if (count > mid) {
                high = mid;
            } 
            // Otherwise, duplicate is in [mid + 1, high]
            else {
                low = mid + 1;
            }
        }

        // Low now holds the duplicate number
        return low;
    }
};
