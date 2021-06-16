#include <bits/stdc++.h>
using namespace std;

int dp[2][201][201];
int mod = 1003;
int solve(string &s, int i, int j, int isTrue)
{
    if(i>j) return 0;
    if(dp[isTrue][i][j] != -1) return dp[isTrue][i][j];
    if( (i==j)  && isTrue ) return dp[isTrue][i][j] = (s[i]=='T');
    if( (i==j)  && (!isTrue) ) return dp[isTrue][i][j] = (s[i]=='F');

    int ans = 0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lT = solve(s, i, k-1, 1);
        int lF = solve(s, i, k-1, 0);

        int rT = solve(s, k+1, j, 1);
        int rF = solve(s, k+1, j, 0);

        if (s[k] == '&')
        {
            if (isTrue)  ans += (lT * rT)%mod;
            else ans += (lF * rF + lT * rF + lF * rT )%mod;
        }
        else if (s[k] == '|')
        {
            if (isTrue) ans += (lT * rT + lT * rF + lF * rT)%mod;
            else ans +=  ( lF * rF )%mod;
        }
        else if (s[k] == '^')
        {
            if (isTrue) ans += (lF * rT + lT * rF)%mod;
            else ans += (lT * rT + lF * rF)%mod;
        }
        ans = ans % mod;
    }
    return dp[isTrue][i][j] = ans%mod;
}
int countWays(int N, string S){
    memset(dp, -1, sizeof(dp));
    return solve(S, 0, N-1, 1);
}

int main()
{
    string s = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    cout << countWays(s.size(), s) << endl;
    return 0;
}
