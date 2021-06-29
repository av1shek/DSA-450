ll findMinDiff(vector<ll> a, ll n, ll m)
{
    sort(a.begin(), a.end());
    ll ans = INT_MAX;
    
    for(int i=0, j = m-1; j<n ; i++, j++)
        ans = min(ans, a[j] - a[i]);
    return ans;
} 