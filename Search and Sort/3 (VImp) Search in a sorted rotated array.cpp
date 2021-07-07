// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/1313987/Brute-Force-Binary-Search-or-O(log-N)-or-C%2B%2B
class Solution {
public:
    int findPivot(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(nums[mid] > nums[h])  l = mid + 1;
            else h = mid;
        }
        return l;
    }
    
    int binarySearch(vector<int> &nums, int l, int h, int x)
    {
        while(l<=h)
        {
            int mid = l + (h-l)/2;

            if(nums[mid] == x) return mid;
            else if(nums[mid] > x) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int x) {
        int pivot = findPivot(nums);

        int a = binarySearch(nums, 0, pivot-1, x);
        if(a!= -1) return a;
        return binarySearch(nums, pivot , nums.size()-1, x);
    }
};

// Another Amazing approach
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple