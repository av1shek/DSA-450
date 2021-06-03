// recursion with memoization - execution time(0.19 gfg)
int dp[101][1000/2 + 1];
bool solve(int arr[], int n, int curr, int sum)
{
    if(curr == sum-curr) return true;
    if(curr > sum/2) return false;
    if(n < 0) return false;
    
    if(dp[n][curr] != -1) return dp[n][curr];
    
    if(solve(arr, n-1, curr + arr[n], sum)){  dp[n][curr] = true; return true; }
    return dp[n][curr] = solve(arr, n-1, curr, sum);
}

int equalPartition(int N, int arr[])
{
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    for(int i=0;i<N;i++) sum += arr[i];
    if(sum%2) return false;
    return solve(arr, N-1, 0, sum);
}
/* --------------------------------------- */
// dp table - execution time(0.25 gfg)
int equalPartition(int n, int arr[])
{
    
    int sum = 0;
    for(int i=0;i<n;i++) sum += arr[i];
    if (sum % 2 != 0) return false;
    bool dp[sum / 2 + 1][n + 1];
    for (int i = 0; i <= n; i++) dp[0][i] = true;
    for (int i = 1; i <= sum / 2; i++) dp[i][0] = false;

    for (int i = 1; i <= sum / 2; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1])
                dp[i][j] = dp[i][j] || dp[i - arr[j - 1]][j - 1];
        }
    }
    
    return dp[sum / 2][n];
}