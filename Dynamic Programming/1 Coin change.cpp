// recursive  - TLE
void solve(int s[], int m, int n, int &ans)
{
    if(n==0)
    {
        ans++;
        return;
    }
    if(m<=0 || n<0) return;
    
    for(int i=0; s[m-1]*i <= n; i++ )
        solve(s, m-1, n-(s[m-1]*i), ans);
}

long long int count( int s[], int m, int n )
{
   int ans = 0;
   solve(s, m, n, ans);
  return ans;
}

// DP table

{
  public:

long long dp[1001][1001];

long long int count( int coin[], int m, int n )
{
    for(int i=0;i<=n;i++) dp[0][i] = 0;
    for(int i=0;i<=m;i++) dp[i][0] = 1; // note that 0, 0 will be 1
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(coin[i-1] <= j)
            dp[i][j] = dp[i-1][j] + dp[i][j-coin[i-1]];
            else 
            dp[i][j] = dp[i-1][j];
        }
    }
   
  return dp[m][n];
}
};