ll minCost(ll arr[], long long n) {
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll> > pq(arr, arr+n);
    while(pq.size() > 1)
    {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        sum += (a+b);
        pq.push(a+b);
    }
    return sum;
}