// recursion with memoization
int dp[101][101];
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}

int optCost(int freq[], int i, int j)
{

    if (j < i)  return 0; // no elements in this subarray
    if (j == i) return freq[i];  // one element in this subarray
    
    if(dp[i][j] != -1) return dp[i][j];
    int fsum = sum(freq, i, j);
    int min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < min) min = cost;
    }
    return dp[i][j] = min + fsum;
}
    
int optimalSearchTree(int keys[], int freq[], int n)
{
    memset(dp, -1, sizeof(dp));
    return optCost(freq, 0, n - 1);
}

// DP table

int dp[101][101];
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++) s += freq[k];
    return s;
}
int optimalSearchTree(int keys[], int freq[], int n)
{
    for (int i = 0; i < n; i++) dp[i][i] = freq[i];

    for (int L = 2; L <= n; L++)
    {
        for (int i=0,j=L-1; j<n;  i++, j++)
        {
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
            {
                int c = ((r > i) ? dp[i][r-1]:0) + ((r < j) ? dp[r+1][j]:0) + sum(freq, i, j);
                if (c < dp[i][j]) dp[i][j] = c;
            }
        }
    }
    return dp[0][n-1];
}