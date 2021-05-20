class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, n), left(n, -1);
        stack<int> s;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(i);
                continue;
            }
            while( (!s.empty()) && (heights[i] <= heights[s.top()]) ) s.pop();
            if(!s.empty())
                right[i] = s.top();
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                continue;
            }
            while( (!s.empty()) && (heights[i] <= heights[s.top()]) ) s.pop();
            if(!s.empty())
                left[i] = s.top();
            s.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
            ans = max(ans, heights[i]*(right[i]-left[i]-1));

        return ans;
    }
};