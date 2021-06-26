int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> mp;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += mp[k-arr[i]];
        mp[arr[i]]++;
    }
    return ans;
}