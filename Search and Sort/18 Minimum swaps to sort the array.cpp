int minSwaps(vector<int>&nums)
{
    vector<pii> arr;
    for(int i=0;i<nums.size();i++)
        arr.push_back({nums[i], i});
   sort(arr.begin(), arr.end());
   int n = nums.size();
   vector<int> vis(n+1, 0);
   int ans = 0;
   
   for(int i=0;i<n;i++)
   {
       if(vis[i]==0)
       {
           int cnt = 0;
           int j = i;
           while(vis[j]==0)
           {
               cnt++;
               vis[j] = 1;
               j = arr[j].second;
           }
           ans += (cnt - 1);
       }
   }
   return ans;
}