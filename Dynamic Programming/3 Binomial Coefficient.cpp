int mod = 1e9 + 7;
int dp[1001][801];
class Solution{
public:
    int nCr(int n, int r){
        for(int i=0;i<=n;i++)
        {
            for (int j = 0; j <= min(i, r); j++) 
            {
                if (j == 0 || j == i) dp[i][j] = 1;
                else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n][r];
    }
};


// Approach 2 (Space Optimised)
int mod = 1e9 + 7;
int dp[1001];
class Solution{
public:
    int nCr(int n, int r){
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            for (int j = min(i, r); j>0; j--) 
            {
                dp[j] = (dp[j-1] + dp[j]) % mod;
            }
        }
        return dp[r];
    }
};