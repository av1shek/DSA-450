class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> a, int n ) {
        unordered_map<ll, ll> cnt;
        cnt[0] = 1;
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            if(i) a[i] += a[i-1];
            cnt[a[i]]++;
            ans += ( cnt[a[i]] - 1 );
        }
        return ans;
    }
};