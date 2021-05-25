// recursion with memoization - (execution time - 0.38 gfg)

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int solve(int wt[], int val[], int n, int w)
    {
        if(n<=0 || w<=0) return 0;
        if(dp[n-1][w] != -1) return dp[n-1][w];
        if(wt[n-1] <= w)
            return dp[n-1][w] = max(solve(wt, val, n-1, w), val[n-1] + solve(wt, val, n-1, w - wt[n-1]));
        return dp[n-1][w] = solve(wt, val, n-1, w);
        
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       memset(dp, -1, sizeof(dp));
       return solve(wt, val, n, w);
    }
};

// DP table - (execution time - 0.12 gfg)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       for(int i=0;i<=n;i++) dp[i][0] = 0;
       for(int i=0;i<=w;i++) dp[0][i] = 0;
       
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=w;j++)
           {
               if(wt[i-1] <= j)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
               else
                    dp[i][j] = dp[i-1][j];
           }
       }
       return dp[n][w];
    }
};