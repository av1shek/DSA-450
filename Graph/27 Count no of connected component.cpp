// It is tarjan algorithm to count no of connected component
class Solution
{
	public:

    bool vis[5001] , onStack[5001];
    int in[5001] , low[5001];
    stack<int> st;
    int timer = 1 , SCC = 0;
    void dfs(int node, vector<int> g[])
    {
    	vis[node] = 1;
    	in[node] = low[node] = timer++;
    	onStack[node] = true;
    	st.push(node);
     
    	for(int u : g[node])
    	{
    		if((vis[u] == true) && (onStack[u] == true))
    			low[node] = min(low[node] , in[u]);
    		else if(vis[u] == false)
    		{
    			dfs(u, g);
    			if(onStack[u] == true)
    			low[node] = min(low[node] , low[u]);
    		}
    	}
 
    	if(in[node] == low[node])
    	{
    		SCC++;
    		int u;
    		while(1)
    		{
    			u = st.top();
    			st.pop() , onStack[u] = false;
    			if(u == node) break;
    		}
    		
    	}
    }
    int kosaraju(int V, vector<int> adj[])
    {
        SCC = 0;
        memset(vis, false, sizeof(vis));
        memset(onStack, false, sizeof(onStack));
        for(int i=0;i<V;i++)
            if(vis[i] == false)
                dfs(i, adj);
        return SCC;
    }
};