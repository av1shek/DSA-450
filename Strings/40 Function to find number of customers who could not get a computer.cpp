// https://www.codingninjas.com/codestudio/problems/count-customers-who-did-not-get-a-computer_1115775?leftPanelTab=0
int countCustomers(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> vis(n+1, 0);
    int cnt = 0, ans = 0;
    for(int i=0;i<n;i++)
    {
        if(vis[arr[i]] == 0)
        {
            vis[arr[i]] = 2;
            cnt++;
            if(cnt > k)
            {
                cnt--;
                ans++;
                vis[arr[i]] = 1;
            } 
        }
        else
        {
            if(vis[arr[i]] == 2)
                cnt--;
        }
    }
    return ans;
}
