// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int indx = 0;
        int l = 0, h = n-1;
        
        while(l<h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] > nums[h])
                l = 1 + mid;
            else
                h = mid;
        }
        return nums[l];
    }
};