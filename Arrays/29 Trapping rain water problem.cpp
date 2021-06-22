// https://www.geeksforgeeks.org/trapping-rain-water/
int trappingWater(int arr[], int n){
    int right[n], left[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    
    for(int i=1;i<n;i++) left[i] = max(arr[i], left[i-1]);
    for(int i=n-2;i>=0;i--) right[i] = max(arr[i], right[i+1]);
    
    int ans = 0;
    for(int i=1;i<n-1;i++)
    {
        int sh = min(right[i], left[i]);
        if(arr[i] < sh) ans += (sh - arr[i]);
    }
    return ans;
}