// variation of rod cutting problem
ll count(ll n)
{
    vector<ll> dp(n+1, 0);

    dp[0] = 1;
    
    /* this will count combinations because here we are first using all 3s, then 5s, 
    and then 10s. */
    for (int i = 3; i <= n; i++)
    dp[i] += dp[i - 3];
     
    for (int i = 5; i <= n; i++)
    dp[i] += dp[i - 5];
     
    for (int i = 10; i <= n; i++)
    dp[i] += dp[i - 10];
    
    
    
    /* this will count permutation because here we 
    are counting 3, 5, 10 in all possible orders
    for(int i=1;i<=n;i++)
    {
        if(i>=3) dp[i] += dp[i - 3];
        if(i>=5) dp[i] += dp[i-5];
        if(i>=10) dp[i] += dp[i-10];
    }*/
 
    return dp[n];
}