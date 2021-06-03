class Solution{
public:

int dp[1001][1001];
    int knapSack(int N, int W, int val[], int wt[])
    {
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(i==0 || j==0) dp[i][j]=0;
                
                else if( wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][W];
    }
};