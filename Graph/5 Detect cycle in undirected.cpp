// DFS
void dfs(int u, int par, vector<int> adj[], vector<bool> &vis, bool &flag)
{
    vis[u] = true;
    
    for(auto v:adj[u])
    {
        if(v==par) continue;
        if(vis[v]) {flag = true; return;}
        dfs(v, u, adj, vis, flag);
    }
}
bool isCycle(int V, vector<int>adj[])
{
    bool flag = false;
    vector<bool> vis(V, false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i, -1, adj, vis, flag);
       if(flag) break;
    }
        
    return flag;
}

// BFS

bool isCycle(int V, vector<int>adj[])
{
    vector<bool> vis(V, false);
    vector<int> parent(V, -1);
    for(int i=0;i<V;i++)
    {
        if(vis[i]) continue;
        queue<int> q;
       q.push(i);
       vis[i] = true;
       while(!q.empty())
       {
           int u = q.front(); q.pop();
           for(auto v:adj[u])
           {
               if(v == parent[u]) continue;
               if(vis[v]) return true;
               vis[v] = true;
               parent[v] = u;
               q.push(v);
           }
       }
    }
        
    return false;
}