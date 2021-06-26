class Solution {
public:
    
    struct compr {
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
        return p1.first < p2.first;
    }
};
    void nextPermutation(vector<int>& nums) {
        bool flag = false;
        priority_queue<pair<int, int>, vector<pair<int, int> >, compr > pq;
        int n = nums.size();
        pq.push({nums[n-1], n-1});
        for(int i=n-2 ; i>=0;i--)
        {
            int val = pq.top().first;
            int pos = pq.top().second;
            if(nums[i] < val)
            {
                pq.pop();
                while(!pq.empty() && (pq.top().first > nums[i]))
                {
                    val = pq.top().first;
                    pos = pq.top().second;
                    pq.pop();
                }
                swap(nums[i], nums[pos]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
            pq.push( {nums[i], i});
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};