// https://leetcode.com/problems/critical-connections-in-a-network/
#define vi vector<int>
#define vvi vector<vector<int> >
class Solution {
public:
    int timer;
    void solve(vi graph[], int node, int par, vi &vis, vi &in, vi &low, vvi &ans)
    {
        vis[node] = 1;
        in[node] = low[node] = timer++;
        
        for(auto child: graph[node])
        {
            if(child == par) continue;
            if(vis[child]) low[node] = min(low[node], in[child]);
            else
            {
                solve(graph, child, node, vis, in, low, ans);
                if(low[child] > in[node])
                    ans.push_back( {node, child});
                low[node] = min(low[node], low[child]);
            }
        }
    }
    vvi criticalConnections(int n, vvi & connec) {
        vector<int> graph[n];
        for(int i=0;i<connec.size();i++)
        {
            int u = connec[i][0];
            int v = connec[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis(n, 0), low(n), in(n);
        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++)
            if(vis[i]==0) solve(graph, i, -1, vis, in, low, ans);
        return ans;
    }
};