#define ll long long
class Solution{
	public:
	ll countTriplets(ll arr[], int n, ll sum)
	{
	    ll cnt = 0;
	    sort(arr, arr+n);
	    for(int k=0;k<n-2;k++)
	    {
	        ll i = k+1, j = n-1;
	        while(i<j)
	        {
	            ll currSum = arr[i] + arr[j] + arr[k];
	            
	            if(currSum >= sum) j--;
	            else
	            {
	                cnt += (j-i);
	                i++;
	            }
	        }
	    }
	    return cnt;
	}
};