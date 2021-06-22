
#define ll long long
ll mod = 1e9 + 7;
ll modMul(ll a, ll b) {return (a*b)%mod; }
class Solution {
  public:

    ll countBT(int h) { 
        vector<int> dp(h+1, 0);
        dp[1] = 1;
        dp[2] = 3;
        for(int i=3;i<=h;i++)
        dp[i] =  ( modMul(dp[i-1], modMul(2, dp[i-2])) + modMul( dp[i-1], dp[i-1] ) )%mod;
        return dp[h]%mod;
    }
};