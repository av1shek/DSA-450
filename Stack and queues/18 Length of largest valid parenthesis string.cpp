class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> stk;
        int ans = 0;
        int n = s.size();
        stk.push(-1);
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') stk.push(i);
            else
            {
                if(!stk.empty()) stk.pop();
                
                if(!stk.empty()) ans = max(ans , i-stk.top());
                else stk.push(i);
            }
        }
        
        return ans;
    }
};