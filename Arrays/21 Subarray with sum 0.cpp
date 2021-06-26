#define ll long long
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        map<int, int> mp;
        mp[0] = 1;
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            sum +=arr[i];
            if(mp.find(sum)!=mp.end())
                return true;
            mp[sum] = 1;
        }
        return false;
    }
};