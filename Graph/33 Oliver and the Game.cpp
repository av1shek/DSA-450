#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"

vector<ll> graph[100001];
vector<ll> intime(100001);
vector<ll> outtime(100001);
ll timer = 0;


void solve()
{
    int t, x, y; cin>>t>>x>>y;
    if(t == 0)
    {

        if( (intime[x] >= intime[1]) && (outtime[x] <= outtime[1]) && (intime[x] < intime[y]) && (outtime[x] > outtime[y]) )
            cout << "YES" << endl;

        else cout << "NO" << endl;
    }
    else
    {

        if( (intime[x] > intime[y]) && (outtime[x] < outtime[y]) )  cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

void dfs(int root, int par)
{
    intime[root] = timer++;
    for(auto v : graph[root])
    {
        if(v == par) continue;
        dfs(v, root);
    }
    outtime[root] = timer++;
}
int main()
{
    fast;
    ll n, a, b; cin>>n;
    for(ll i=1;i<n;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll q; cin>>q;
    dfs(1, -1);
    while(q--) solve();
    return 0;
}
