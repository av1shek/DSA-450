// https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/115541/JavaC%2B%2BPython-Priority-Queue-Solution

#define pii pair<int, int>
class Solution {
public:
    int solve(int src, int dist, vector<vector<int> > &dp, int k, vector<pii> graph[])
    {
        if(src == dist) return 0;
        if(k==-1) return INT_MAX;
        if(dp[src][k] != -1) return dp[src][k];
        int ans = INT_MAX;
        
        for(auto it: graph[src])
        {
            int temp = solve(it.first, dist, dp, k-1, graph);
            if(temp == INT_MAX) continue;
            ans = min(ans, it.second + temp);
        }
            
        return dp[src][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pii> graph[n+1];
        vector<vector<int> > dp(n+1, vector<int>(k+1, -1));
        for(auto flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            
            graph[u].push_back({v, w});
        }
        int ans = solve(src, dst, dp, k, graph);
        return (ans == INT_MAX ? -1 : ans );
    }
};