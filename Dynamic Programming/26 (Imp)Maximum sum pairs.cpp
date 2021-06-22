int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        int dp[n];
        sort(arr, arr+n);
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        
        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1];
            
            if(arr[i] - arr[i-1] < k)
            {
                if(i>=2)
                    dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
                else
                    dp[i] = max(dp[i], arr[i] + arr[i-1]);
            }
        }
        return dp[n-1];
    }