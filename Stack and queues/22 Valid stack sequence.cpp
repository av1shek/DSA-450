class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        int i=0, j=0;
        for( ;i<n;i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && (s.top()==popped[j]) )
            {  s.pop(); j++; } 
        }
        return ( (j==n) && s.empty());
    }
};