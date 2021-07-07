int wordBreak(string A, vector<string> &B) {
    int n = A.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=0;i<n;i++)
    {
        if(dp[i])
        {
            for(auto word : B)
            {
                if( A.substr(i, word.size()) == word )
                    dp[i+word.size()] = 1;
            }
        }
    }
    return dp[n];
}