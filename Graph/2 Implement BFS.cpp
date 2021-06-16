vector<int>bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<bool> vis(V, false);
    vector<int> ans;
    q.push(0);
    vis[0] = true;
    
    while(!q.empty())
    {
        int u = q.front();q.pop();
        ans.push_back(u);
        for(auto v: adj[u])
        {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
        }
    }
    return ans;
}