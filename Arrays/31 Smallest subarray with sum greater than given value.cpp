// sliding window
int sb(int arr[], int n, int x)
    {
        int ans = n, start = 0, sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum > x)
            {
                while( (sum - arr[start] > x) && (start <i) ) 
                {  sum -= arr[start]; start++; } 
                ans = min(ans, i-start + 1);
            }
        }
        return ans;
    }