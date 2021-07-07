// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = firstOccur(nums, target, 'f');
        ans[1] = firstOccur(nums, target, 'l');
        return ans;
    }
    int firstOccur(vector<int> &arr, int tar, char c)
    {
        int res = -1;
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == tar) 
            {
                res = mid;
                if(c=='f') right = mid - 1;
                else left = mid + 1; 
                
            } 
            else if (arr[mid] > tar)  right = mid - 1;
            else  left = mid + 1;
        }
        return res;
    }
};