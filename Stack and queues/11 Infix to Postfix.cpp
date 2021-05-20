#include<bits/stdc++.h>
using namespace std;

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for(char c: s)
    {
        if(isalpha(c))
            result += c;
        else if( c == '(' )
            st.push(c);
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(c) <= prec(st.top())) {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        char temp = st.top();
        st.pop();
        result += temp;
    }
    return result;
}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp) << endl;
    return 0;
}
