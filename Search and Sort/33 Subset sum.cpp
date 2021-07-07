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

vector<ll> solve(ll arr[], ll st, ll en)
{
    ll len = en - st + 1;
    vector<ll> v;
    for(ll i=0; i<(1<<len); i++)
    {
        ll sum = 0;
        for(ll j=0;j<len;j++)
        {
            if(i&(1<<j))
                sum += arr[st + j];
        }
        v.push_back(sum);
    }
    return v;
}

void testcase()
{
    ll n, a, b; cin>>n>>a>>b;
    ll arr[n]; scanarr(arr, n);
    vector<ll> v1 = solve(arr, 0, n/2);
    vector<ll> v2 = solve(arr, n/2 + 1, n-1); sort(v2.begin(), v2.end());

    //debug(v1);
    //debug(v2);
    ll ans = 0;
    for(ll i=0;i<v1.size();i++)
    {
        ll lef = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        ll rig = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        ans += (rig - lef);
    }
    cout << ans ;
    return;
}


int main()
{
    fast;
    ll tc=1;
    //cin>>tc;

    for(ll i=1;i<=tc;i++)
    {
        //cout<<"Case #"<<i<<": ";
        testcase();
    }
    return 0;
}
