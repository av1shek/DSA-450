// DFS
void dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &visStk, int u, bool &flag)
{
    if(vis[u]) return;
    vis[u] = true;
    visStk[u] = true;
    
    for(auto v:adj[u])
    {
        if(visStk[v]) { flag=true; return; }
        if(vis[v]) continue;
        dfs(adj, vis, visStk, v, flag);
        if(flag) return;
    }
    
    visStk[u] = false;
}
bool isCyclic(int V, vector<int> adj[]) 
{
   	vector<bool> vis(V, false);
   	vector<bool> visStk(V, false);
   	bool flag = false;
   	
   	for(int i=0;i<V;i++)
   	{
   	    if(vis[i]) continue;
   	    dfs(adj, vis, visStk, i, flag);
   	    if(flag) break;
   	}
   	return flag;
}

//BFS

bool isCyclic(int V, vector<int> adj[]) 
{
   	vector<int> inDeg(V, 0);
   	for(int u=0;u<V;u++)
   	    for(auto v:adj[u]) inDeg[v]++;
   	
   	queue<int> q;
   	int cnt = 0;
   	
   	for(int i=0;i<V;i++)
   	    if(inDeg[i]==0)
   	        q.push(i);
   	
   	
   	while(!q.empty())
   	{
   	    int u = q.front(); q.pop();
   	    cnt++;
   	    for(auto v: adj[u])
   	    {
   	        inDeg[v]--;
   	        if(inDeg[v]==0){ inDeg[v]--; q.push(v); }
   	    }
   	}
   	return !(cnt==V);
}