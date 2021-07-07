#define ll long long
class Solution 
{
    public:
    
    ll solve(int arr[], int n, ll page)
    {
        ll cnt = 0;
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum > page)
            {
                cnt++;
                sum = arr[i];
            }
        }

        if(sum > page) cnt++;
        cnt++;

        return cnt;
    }
    ll findPages(int arr[], int n, int m) 
    {
        if(n<m) return -1;
        int maxx = 0;
        
        for(ll i=0;i<n;i++)
            maxx = max(maxx, arr[i]);
            
        ll low = maxx, high = 1e9;
        ll ans;
        while(low<high)
        {
            ll mid = low + (high-low)/2;
            ll temp = solve(arr, n, mid);
            if(temp > m)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid;
            }
        }
        return ans;
    }
};