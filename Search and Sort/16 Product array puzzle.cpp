#define ll long long int
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<ll> productExceptSelf(vector<ll>& nums, int n) {
       vector<ll> pre = nums, suff = nums, pro(n);
       
       for(ll i=1;i<n;i++)
       {
           pre[i] *= pre[i-1];
           suff[n-i-1] *= suff[n-i];
       }
       
       for(ll i=0;i<n;i++)
       {
           ll lef = (i!=0) ? pre[i-1] : 1;
           ll rig = (i!=n-1) ? suff[i+1] : 1;
           pro[i] = lef * rig;
       }
       return pro;
    }
};

// Another approach
/*
let P be the product of all numbers
pro[i] = p / nums[i];
but this will not work when any element of array is 0. ( divided by 0 exception)
We have to count number of 0 in array and handle it.
Implementation of that is
https://ancorecodes.herokuapp.com/problem/60cadbdef06414000423cb8d
*/