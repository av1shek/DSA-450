int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int> dist(n, INT_MAX);
    
    dist[0] = 0;
    for(int i=1;i<=n;i++)
    {
        bool flag = true;
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if( (dist[u]!=INT_MAX) && (dist[v] > dist[u] + w) )
            {
               flag = false;
               dist[v] = dist[u] + w;
            }
        }
        if(flag) break;
        else if(i==n) return 1;
    }
    return 0;
}