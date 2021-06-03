int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if(n<0) return INT_MIN;
    if(n==0) return 0;
    
    if(dp[n]!=-1) return dp[n];
    
    dp[n] = max(1+solve(n-x, x, y, z, dp),
                max( 1+solve(n-y, x, y, z, dp), 
                     1+ solve(n-z, x, y, z, dp)));
    return dp[n];
    
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n+1, -1);
    solve(n, x, y, z, dp);
    return max(dp[n], 0);
}