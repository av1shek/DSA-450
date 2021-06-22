// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1#
// cpp_int is defined in boost library

cpp_int findCatalan(int n) 
    {
        cpp_int dp[101];
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
                dp[i] += dp[j] * dp[i - j - 1];
        }
        return dp[n];
    }