// Recursion with memoization
    long long mod = 1e9 + 7;
    long long dp[1001][1001];
    string s;
    long long solve(int i, int j)
    {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j])
            dp[i][j] = (1 + solve(i, j-1) + solve(i+1, j))%mod;
        else
            dp[i][j] = ( (solve(i, j-1) + solve(i+1, j))%mod + mod - solve(i+1, j-1))%mod;
        return dp[i][j];
    }
    long long int  countPS(string str)
    {
       int n = str.size();
       s = str;
       memset(dp, -1, sizeof(dp));
       return solve(0, n-1);
    }
     

// DP
    long long mod = 1e9 + 7;
    long long dp[1001][1001];
    long long int  countPS(string b)
    {
       int N = b.length();
       memset(dp, 0, sizeof(dp));
     
        // palindromic subsequence of length 1
        for (int i = 0; i < N; i++)
            dp[i][i] = 1;

        for (int L = 2; L <= N; L++) {
            for (int i = 0; i <= N-L; i++) {
                int k = L + i - 1;
                if (b[i] == b[k])
                    dp[i][k] = (dp[i][k - 1] + dp[i + 1][k] + 1)%mod;
                else
                    dp[i][k] = ( (dp[i][k - 1] + dp[i + 1][k])%mod + mod - dp[i + 1][k - 1])%mod;
            }
        }
     
        return dp[0][N - 1];
    }
     
};