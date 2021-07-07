#define ll long long
ll mod = 1e9 + 7;
class Solution{
    public:
    string s;
    int dp[1001][1001];
    ll solve(int i, int j)
    {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i]==s[j])
            dp[i][j] = 1 + ( solve(i+1, j) + solve(i, j-1) ) % mod;
        else
            dp[i][j] =  ( (solve(i, j-1) + solve(i+1, j))%mod + mod - solve(i+1, j-1))%mod;
        return dp[i][j];
    }
    long long int  countPS(string str)
    {
       s = str;
       memset(dp, -1, sizeof(dp));
       return solve(0, str.size()-1);
    }
     
};