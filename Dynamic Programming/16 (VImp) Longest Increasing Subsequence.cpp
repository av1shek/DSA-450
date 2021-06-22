// https://leetcode.com/problems/longest-increasing-subsequence/submissions/
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/74848/9-lines-C%2B%2B-code-with-O(NlogN)-complexity
// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// https://youtu.be/TocJOW6vx_I

int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}