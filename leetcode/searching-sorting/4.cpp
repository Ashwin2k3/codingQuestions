/*
   class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums.size();
        int n = n1 + n2 ;
        int l= 0, r = n1 ;
        while (l <= r ) {   
            int m1 = (l + r)/2 ;
            int l1 = -1e9;
            int r1 = 1e9;
            int l2 = -1e9;
            int r2 = 1e9;
            int m2 = (n+1)/2-m1;
            if (m1 < n1) {
               r1 = nums1[m2];
            }
            if (m2 < n2 ) {
                r2 = nums2[m2];
            }
            if (m1 - 1 >= 0) {
                l1 = nums1[m1 -1];
            }
            if (m2 - 1 >= 0) {
                l2 = nums2[m2 - 1];
            }

            if (l1 <= r2 and l2 <= r1 ) {
                if (n1 % 2 == 1) {
                    return max(l1, l2);
                }
                else{
                    double ans = (min(r1,r2) + max(l1, l2));
                    ans/=2.0;
                    return ans;
                }
            }

            else if (l1 > l2) {
                r = m1 - 1;

            }
            else{
                l = m1 + 1 ;

            }
        }

        return 0.0;
        
        
    }
};



*/


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize binary search range
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0, r = n1;

        while (l <= r) {
            int m1 = (l + r) / 2;
            int m2 = (n1 + n2 + 1) / 2 - m1;

            // Boundary elements or actual elements around partitions
            int l1 = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int r1 = (m1 == n1) ? INT_MAX : nums1[m1];
            int l2 = (m2 == 0) ? INT_MIN : nums2[m2 - 1];
            int r2 = (m2 == n2) ? INT_MAX : nums2[m2];

            // Check if we found the correct partition
            if (l1 <= r2 && l2 <= r1) {
                // If total number of elements is even
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                // If total number of elements is odd
                else
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                // Move m1 left
                r = m1 - 1;
            }
            else {
                // Move m1 right
                l = m1 + 1;
            }
        }
        return 0.0;  // In case of an unexpected input, though we should never reach here
    }
};

