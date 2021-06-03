int dp[1001][1001];
int longestCommonSubstr (string a, string b, int n, int m)
{
    int ans = 0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}