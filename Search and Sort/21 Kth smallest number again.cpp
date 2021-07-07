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
    ll n, q; cin>>n>>q;
    vector<pii> arr;
    ll a, b;
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    vector<pii> intervals;
    intervals.push_back(arr[0]);
    for(ll i=1;i<n;i++)
    {
        if(arr[i].first <= intervals.back().second)
        {
            ll sz = intervals.size();
            intervals[sz - 1].second = max(intervals[sz-1].second, arr[i].second);
        }
        else
            intervals.push_back(arr[i]);
    }

    vector<pii> pos;
    ll indx = 1;
    for(auto interval : intervals)
    {
        ll diff = interval.second - interval.first;
        pos.push_back({indx, indx+diff});
        indx = indx + diff + 1;
    }

    ll k;
    while(q--)
    {
        cin>>k;
        ll low = 0, high = intervals.size() - 1;
        indx = -1;
        while(low <= high)
        {
            ll mid = low + (high - low)/2;

            if( (k>=pos[mid].first) && (k <= pos[mid].second))
            {
                indx = mid;
                break;
            }
            if( k < pos[mid].first )
                high = mid - 1;
            else
                low = mid + 1;
        }

        if(indx == -1) cout << indx << endl;
        else
        {
            ll diff = k - pos[indx].first;
            cout << intervals[indx].first + diff << endl;
        }
    }

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
