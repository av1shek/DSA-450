#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll      long long
#define ull     unsigned long long
#define pii     pair<long long, long long>
#define pb      push_back
#define all(x)  (x).begin(), (x).end()
#define endl    "\n"




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



template <typename T>
void printarr(vector<T> &v)
{
    for(T it : v) cout << it << " ";
    cout << endl;
}

template <typename T>
void scanarr(vector<T> &v, ll n)
{
    for(ll i=0;i<n;i++) cin>>v[i];
}

ll solve(vector<ll> &arr, ll h)
{
    ll wood = 0;
    for(auto it : arr)
        wood += max(0ll, it - h);
    return wood;
}
void testcase()
{
    ll n, m; cin>>n>>m;
    vector<ll> h(n); scanarr(h, n);
    ll maxx = *max_element(all(h));

    ll low = 0, high = maxx, ans;
    while(low <= high)
    {
        ll mid = low + (high-low)/2;
        ll temp = solve(h, mid);

        if(temp >= m)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
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
