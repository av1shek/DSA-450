void backtrack(vector<vector<int>> &cost, vector<int> &vis, int curr, int cnt, int currCost, int &ans)
{
    if(cnt == cost.size()-1)
    {
        ans = min(ans, cost[curr][0] + currCost);
        return;
    }
    
    for(int i=0;i<cost.size();i++)
    {
        if(!vis[i] && cost[curr][i])
        {
            vis[i] = true;
            backtrack(cost, vis, i, cnt+1, currCost + cost[curr][i], ans);
            vis[i] = false;
        }
    }
}
int total_cost(vector<vector<int>> &cost){
    int n = cost.size();
    vector<int> vis(n, false);
    int ans = INT_MAX;
    vis[0] = true;
    backtrack(cost, vis, 0, 0, 0, ans);
    return ans;
}