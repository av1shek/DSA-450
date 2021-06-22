int maxSubstring(string s)
{
    int n = s.size();
    int cnt = 0;
    int ans = -1;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '0')
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            if(cnt>0) cnt--;
        }
    }
    return ans;
}