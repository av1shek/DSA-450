char* reverse(char *S, int len)
{
    stack<char> stk;
    for(int i=0;i<len;i++) stk.push(S[i]);
    for(int i=0;i<len;i++) { S[i] = stk.top(); stk.pop(); }
    return S;
}