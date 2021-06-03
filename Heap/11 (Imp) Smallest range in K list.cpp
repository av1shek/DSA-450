vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    if(k==1) return { nums[0][0], nums[0][0] };

    vector<int> pos(k, 0);
    vector<int> ans;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int mini = INT_MAX, maxi = INT_MIN;

    for(int i=0;i<k;i++)
    {
        if(nums[i].size() > 0) {
            pq.push( {nums[i][0], i } );
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
    }
    ans = {mini, maxi};

    while(true)
    {
        pii curr = pq.top(); pq.pop();
        int i = curr.second;
        pos[i]++;

        if(pos[i] < nums[i].size())
        {
            int val = nums[i][pos[i]];
            pq.push({val, i});
        }
        else 
            break;

        mini = pq.top().first;
        maxi = max(maxi, nums[i][pos[i]]);

        if(maxi - mini < ans[1]-ans[0] ) ans = {mini, maxi};
    }
    return ans;
}