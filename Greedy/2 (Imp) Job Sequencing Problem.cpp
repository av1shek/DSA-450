static bool comp(Job &j1, Job &j2)
{
    if(j1.profit != j2.profit)
        return j1.profit > j2.profit;
    return j1.dead < j2.dead;
}
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    bool vis[102]; memset(vis, false, sizeof(vis));
    sort(arr, arr+n, comp);
    int profit  = arr[0].profit;
    int cnt = 1;
    vis[arr[0].dead] = true;

    for(int i=1;i<n;i++)
    {
        int d = arr[i].dead;
        while(d>0 && vis[d]) d--;
        if(d<=0) continue;
        profit += arr[i].profit;
        cnt++;
        vis[d] = true;
    }
    vector<int> ans = {cnt, profit};
    return ans;
} 