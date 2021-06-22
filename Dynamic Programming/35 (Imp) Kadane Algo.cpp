int maxSubarraySum(int arr[], int n){
        int ans = 0, sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
        }
        return ans;
    }