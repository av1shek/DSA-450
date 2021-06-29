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


void testcase()
{
    ll n; cin>>n;
    ll a[n]; scanarr(a, n);
    sort(a, a+n, greater<int>());
    ll cnt = 0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            cnt++;
            cout <<"1 ";
        }
    }
    if((n-cnt)==2 && a[0]==3 && a[1] == 2)
        cout << 2 << " " << 3 ;
    else
        for(ll i=0;i<(n-cnt);i++)
            cout << a[i] << " ";
    cout << endl;
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
