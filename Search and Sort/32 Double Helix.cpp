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

ll solve(vector<ll> &arr, ll t)
{
    ll cnt = 0;
    for(ll i=0;i<arr.size();i++)
    {
        ll curr = arr[i];
        ll j = 2;
        while(curr <= t)
        {
            cnt++;
            curr += j*arr[i];
            j++;
        }
    }
    return cnt;
}
void testcase()
{
    while(true)
    {
        ll n1; cin>>n1; if(n1 == 0) return;
        vector<ll> s1(n1); scanarr(s1, n1);
        ll n2; cin>>n2;
        vector<ll> s2(n2); scanarr(s2, n2);

        ll prev = 0, sum1 = 0, sum2 = 0;
        ll i = 0, j = 0;

        while((i<n1) && (j<n2))
        {
            if(s1[i] < s2[j])
                sum1 += s1[i++];
            else if(s1[i] > s2[j])
                sum2 += s2[j++];
            else
            {
                sum1 += s1[i++];
                sum2 += s2[j++];
                prev = max(sum1, sum2);
                sum1 = sum2 = prev;
            }
        }

        while(i<n1)
            sum1 += s1[i++];
        while(j<n2)
            sum2 += s2[j++];

        cout << max(sum1, sum2) << endl;
    }
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
