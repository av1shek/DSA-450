bool cmp(const val&a,const val&b){ return(a.second<b.second); }
int maxChainLen(struct val p[],int n)
{
    int dp[n+1];
    int ans = 1;
    sort(p, p+n, cmp);
    for(int i=0;i<=n;i++) dp[i] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[i].first > p[j].second)
            {
                dp[i] = max(dp[i], 1+dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}