// https://youtu.be/ww4V7vRIzSk
// recursion with memoization
#define ll long long
//Function to find the maximum possible amount of money we can win.
ll dp[1001][1001];
ll solve(int arr[], int low, int high)
{
    if(low == high) return arr[low];
    if(dp[low][high] != -1) return dp[low][high];
    if(low + 1 == high) return dp[low][high] = max(arr[low], arr[high]);
    int val1 = arr[low] + min(solve(arr, low+2, high), solve(arr, low+1, high-1) );
    int val2 = arr[high] + min(solve(arr, low, high-2), solve(arr, low+1, high-1));
    return dp[low][high] = max(val1, val2);
}

ll maximumAmount(int arr[], int n) 
{
    memset(dp, -1, sizeof(dp));
    return solve(arr, 0, n-1);
}


// DP table
#define ll long long
ll dp[1001][1001];
ll maximumAmount(int arr[], int n) 
{
    memset(dp, -1, sizeof(dp));
    for(int len = 0;len < n; len++)
    {
        for(int i=0, j=len; j<n; i++, j++)
        {
            if(len ==0) dp[i][j] = arr[i];
            else if(len == 1) dp[i][j] = max(arr[i], arr[j]);
            else
            {
                int val1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int val2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(val1, val2);
            }
        }
    }
    return dp[0][n-1];
}