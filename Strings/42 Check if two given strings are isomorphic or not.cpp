class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string a, string b)
    {
        if(a.size() != b.size()) return false;
        int cnt[26]; memset(cnt, -1, sizeof(cnt));
        int vis[26]; memset(vis, 0, sizeof(vis));
        for(int i=0;i<a.size();i++)
        {
            if(cnt[a[i]-'a'] == -1)
            {
                if(vis[b[i]-'a'] == 0)
                {
                    cnt[a[i] - 'a'] = b[i] - 'a';
                    vis[b[i] - 'a'] = 1;
                }
                else
                    return false;
                
            }
            else if(cnt[a[i]-'a']!=b[i] - 'a')
                return false;
        }
        return true;
    }
};