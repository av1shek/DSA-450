vector<string> AllPossibleStrings(string s)
{
    int n = s.size();
    vector<string> ans;
    for(int i=0;i<(1<<n);i++)
    {
        string res;
        for(int j = 0;j<n;j++)
        {
            if(i&(1<<j))
                res.push_back(s[j]);
        }
        if(res.size())
            ans.push_back(res);
    }
    sort(ans.begin(), ans.end());
    return ans;
}