https://www.hackerrank.com/challenges/board-cutting/copy-from/221006583
#define ll long long
ll mod = 1e9 + 7;
long long boardCutting(vector<int> x, vector<int> y) {
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());
    ll n = x.size(), m = y.size();
    ll horcut = 1, vercut = 1;
    ll cost = 0, i = 0, j = 0;
    while( i<n && j<m )
    {
        if(x[i] < y[j])
        {
            cost = (cost + y[j]*horcut)%mod;
            vercut++;
            j++;
        }
        else {
            cost = (cost + x[i]*vercut)%mod;
            horcut++;
            i++;
        }
    }
    while(i<n)
    {
        cost = (cost + x[i]*vercut)%mod;
        i++;
    }
    while(j<m)
    {
        cost = (cost + y[j]*horcut)%mod;
        j++;
    }
    return cost;
}