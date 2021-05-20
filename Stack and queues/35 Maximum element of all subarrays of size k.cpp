class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<k-1;i++)
        {
            while( (!q.empty()) && (nums[i] > nums[q.back()]) ) q.pop_back();
                q.push_back(i);
        }
        int j = 0;
        
        for(int i=k-1;i<nums.size();i++, j++)
        {
            if( (!q.empty()) && (q.front() < j ) ) q.pop_front();
            while( (!q.empty()) && (nums[i] > nums[q.back()]) ) q.pop_back();
                q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};