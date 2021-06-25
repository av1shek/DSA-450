https://leetcode.com/problems/interleaving-string/
// recursion with memoization
int dp[101][101];
    bool solve(string &a, int i, string &b, int j, string &c, int k)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(i<a.size() && j<b.size())
        {
            if( (a[i] == c[k]) && solve(a, i+1, b, j, c, k+1) )
                return dp[i][j] = 1;
            if( (b[j] == c[k]) && solve(a, i, b, j+1, c, k+1) )
               return dp[i][j] = 1;
             return dp[i][j] = 0;
        }
        else 
        {
            while(i<a.size()) 
            {
                if(a[i] != c[k])
                    return false;
                i++; k++;
            }
            
            while(j<b.size()) 
            {
                if(b[j] != c[k])
                    return false;
                j++; k++;
            }
        }
        return true;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof(dp));
        return solve(s1, 0, s2, 0, s3, 0);
    }

// DP table

class Solution {
public:
int dp[101][101];
bool isInterleave(string s1, string s2, string s3) {
    if(s1.size() + s2.size() != s3.size()) return false;
    dp[0][0] = 1;
    
    for(int i=1;i<=s1.size();i++)
        dp[i][0] = (dp[i-1][0]) && (s1[i-1]==s3[i-1]);
    for(int j=1;j<=s2.size();j++)
        dp[0][j] = (dp[0][j-1]) && (s2[j-1]==s3[j-1]);
        
    for(int i=1;i<=s1.size(); i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1] == s3[i+j-1])
                dp[i][j] = dp[i-1][j];
            if(s2[j-1] == s3[i+j-1])
                dp[i][j] = dp[i][j-1] || dp[i][j];
            
        }
    }
    return dp[s1.size()][s2.size()];
}
};