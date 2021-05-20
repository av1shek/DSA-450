
bool comp(vector<int> &a, vector<int> &b)
{
    if(a[0]!=b[0]) return a[0] < b[0];
    return a[1] > b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        stack<vector<int> > s;
        s.push(intervals[0]);
        int n = intervals.size();
        for(int i=1;i<n;i++)
        {
            vector<int> temp = s.top();
            vector<int> curr = intervals[i];
            if(temp[1]>=curr[0])
            {
                s.pop();
                temp[1] = max(curr[1], temp[1]);
                s.push(temp);
            }
            else
                s.push(curr);
        }
        vector<vector<int> > ans(s.size());
        for(int i=s.size()-1;i>=0;i--)
        {
            ans[i] = s.top(); s.pop();
        }
        return ans;
    }
};