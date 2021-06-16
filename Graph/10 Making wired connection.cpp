class Solution {
public:
    void dfs(int curr, vector<bool> &vis, vector<int> graph[])
    {
        vis[curr] = 1;
        for(auto v:graph[curr])
            if(!vis[v]) dfs(v, vis, graph);
    }
    int makeConnected(int n, vector<vector<int>>& cables) {
        if(cables.size() < n-1) return -1;
        vector<int> graph[n];
        
        for(auto it:cables) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, 0);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            dfs(i, vis, graph);
            cnt++;
        }
        return cnt-1;
    }
};