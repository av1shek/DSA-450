void dfs(vector<int> adj[], vector<int> &ans, vector<bool> &vis, int u)
{
    if(vis[u]) return;
    
    vis[u] = true;
    ans.push_back(u);
    
    for(auto v:adj[u])
    {
        if(vis[v]) continue;
        dfs(adj, ans, vis, v);
    }
    
}
vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> vis(V, false);
    dfs(adj, ans, vis, 0);
    return ans;
}