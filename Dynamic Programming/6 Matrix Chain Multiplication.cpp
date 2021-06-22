// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Recursive with memoization
int solve(int nums[], int i, int j, vector<vector<int> > &dp)
{
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
        ans = min(ans, solve(nums, i, k, dp) + solve(nums, k+1, j, dp) + nums[i-1] * nums[k] * nums[j]);
    return dp[i][j] = ans;
}
int matrixMultiplication(int n, int nums[])
{
    vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    return solve(nums, 1, n-1, dp);
}


// DP table
int matrixMultiplication(int n, int nums[])
{
    vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    for(int i=0;i<=n;i++) dp[i][i] = 0;
    
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = dp[i][k] + dp[k + 1][j]
                    + nums[i - 1] * nums[k] * nums[j];
                if (q < dp[i][j])  dp[i][j] = q;
            }
        }
    }
    
    return dp[1][n-1];
}