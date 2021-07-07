// https://leetcode.com/problems/interleaving-string/
class Solution {
public:
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
};