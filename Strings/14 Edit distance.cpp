int dp[101][101];
int editDistance(string s, string t) {
    int m = s.size(), n = t.size();
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(s[i-1] == t[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]});
                // replace, insert, remove
                // replace => 1 + cost cal till m-1, n-1
                // insert => 1 + cost cal till m, n-1
                // remove => 1 + cost cal till m-1, n
        }
    }
    return dp[m][n];
}