class Solution
{
    public:
    int precd(char ch)
    {
        if( ch=='+' || ch=='-') return 1;
        if( ch=='/' || ch=='*') return 2;
        return 0;
    }
    int eval(int a, char ch, int b)
    {
        if(ch=='+') return a+b;
        if(ch=='-') return a-b;
        if(ch=='*') return a*b;
        return a/b;
    }
    int evaluatePostfix(string s)
    {
        stack<int> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            stk.push(s[i]-'0');
            else
            {
                int oprnd1 = stk.top(); stk.pop();
                int oprnd2 = stk.top(); stk.pop();
                stk.push(eval(oprnd2, s[i], oprnd1));
            }
        }
        return stk.top();
    }
};