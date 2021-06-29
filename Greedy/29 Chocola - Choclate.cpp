// same 12th question
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pii pair<long long, long long>
#define endl "\n"



/// -----------------------------------------------------------------
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr  << #x << " = "; _print(x)
#else
#define debug(x...)
#endif
/// ------------------------------------------------------------------------------



void printarr(ll a[], ll n)
{
    for(ll i=0;i<n;i++) cout << a[i] << " " ;
    cout << endl;
}

void scanarr(ll a[], ll n)
{
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

ll solve(vector<ll> &x, vector<ll> &y) {
    sort(x.begin(), x.end(), greater<ll>());
    sort(y.begin(), y.end(), greater<ll>());
    ll n = x.size(), m = y.size();
    ll horcut = 1, vercut = 1;
    ll cost = 0, i = 0, j = 0;
    while( i<n && j<m )
    {
        if(x[i] < y[j])
        {
            cost = (cost + y[j]*horcut);
            vercut++;
            j++;
        }
        else {
            cost = (cost + x[i]*vercut);
            horcut++;
            i++;
        }
    }
    while(i<n)
    {
        cost = (cost + x[i]*vercut);
        i++;
    }
    while(j<m)
    {
        cost = (cost + y[j]*horcut);
        j++;
    }
    return cost;
}
void testcase()
{
    ll m, n, temp; cin>>m>>n;
    vector<ll> x, y;
    for(ll i=0;i<m-1;i++)
    {
        cin>>temp;
        x.push_back(temp);
    }
    for(ll i=0;i<n-1;i++)
    {
        cin>>temp;
        y.push_back(temp);
    }
    cout << solve(x, y) << endl;
    return;
}


int main()
{
    fast;
    ll tc=1;
    cin>>tc;

    for(ll i=1;i<=tc;i++)
    {
        //cout<<"Case #"<<i<<": ";
        testcase();
    }
    return 0;
}
