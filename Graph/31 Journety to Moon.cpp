void dfs(int node, vector<long long> graph[], vector<bool> &vis, long long &cnt)
{
    vis[node] = 1;
    cnt++;
    for(auto v : graph[node])
        if(!vis[v])
            dfs(v, graph, vis, cnt);
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<bool> vis(n+1, false);
    vector<long long> graph[n+1];
    for(auto p : astronaut)
    {
        int u = p[0], v = p[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    long long curr;
    vector<long long> cnt;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            curr = 0;
            dfs(i, graph, vis, curr);
            cnt.push_back(curr);
        }
    }
    n = cnt.size();
    long long ans = 0;

    for(int i = n-2; i>=0;i--){
        ans += (cnt[i]*cnt[i+1]);
        cnt[i] += cnt[i+1];
    } 

    return ans;
}