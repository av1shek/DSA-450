long long mod = 1e9 + 7;
class Solution{
    public:
    long long Maximize(int arr[],int n)
    {
        sort(arr, arr+n);
        long long sum = 0;
        for(int i=0;i<n;i++)
            sum = ( mod + sum + (mod + i*(long long)arr[i])%mod )%mod;
        return sum;
    }
};