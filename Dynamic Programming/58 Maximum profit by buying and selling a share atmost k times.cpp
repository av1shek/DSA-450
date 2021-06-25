class Solution {
  public:
  int dp[201][501];
    
    int maxProfit(int k, int n, int prices[]) {
        memset(dp, 0, sizeof(dp));
        for(int t=1;t<=k;t++)
        {
            int maxi = INT_MIN;
            for(int d=1;d<n;d++)
            {
                maxi = max(maxi, dp[t-1][d-1] - prices[d-1]);
                dp[t][d] = max(dp[t][d-1],  maxi + prices[d]);
            }
        }
        return dp[k][n-1];
    }
};