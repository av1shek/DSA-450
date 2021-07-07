int cost(string &s, char ch)
{
    int cnt = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] != ch) cnt++;
        ch = '1' - ch + '0';
    }
    return cnt;
}
int minFlips (string s)
{
    return min(cost(s, '0'), cost(s, '1'));
}