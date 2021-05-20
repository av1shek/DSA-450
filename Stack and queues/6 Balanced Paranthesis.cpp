class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.size();i++)
        {
            if( x[i]=='(' || x[i]=='{' || x[i]=='[') 
                s.push(x[i]);
            else if( x[i]==')')
            {
                if(s.empty()) return false;
                if(s.top() != '(') return false;
                s.pop();
            } 
            else if( x[i]=='}')
            {
                if(s.empty()) return false;
                if(s.top() != '{') return false;
                s.pop();
            } 
            else if( x[i]==']')
            {
                if(s.empty()) return false;
                if(s.top() != '[') return false;
                s.pop();
            } 
        }
        return s.empty();
    }

};