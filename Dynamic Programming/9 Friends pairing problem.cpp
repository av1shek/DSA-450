int mod = 1e9 + 7;
long long dp[1000001];
int countFriendsPairings(int n) 
{ 
    if(n<=2) return n;
    int ans = 0;
    dp[0] = 0; dp[1] = 1; dp[2] = 2;
    
    for(int i=3;i<=n;i++)
    {
        dp[i] = (dp[i-1] + ((i-1)*dp[i-2])%mod )%mod;
    }
    return dp[n];
}

// Approach 2 - O(1) space
int mod = 1e9 + 7;
int countFriendsPairings(int n) 
{ 
    if(n<=2) return n;
    long long ans = 0;
    long long prev = 1, curr = 2;
    
    for(int i=3;i<=n;i++)
    {
        ans = (curr + ((i-1)*prev)%mod )%mod;
        prev = curr;
        curr = ans;
    }
    return ans;
}