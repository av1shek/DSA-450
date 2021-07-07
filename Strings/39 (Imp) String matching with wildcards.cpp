// recursion - here many overlapping problems are there 
// so it is better to use dp here
class Solution{
    public:
    bool solve(string &wild, string &pattern, int i, int j)
    {
        if(i==wild.size() && j==pattern.size()) return true;
        if(i==wild.size() && j!=pattern.size()) return false;
        if(j==pattern.size())
        {
            while(i<wild.size() && wild[i]=='*') i++;
            return i==wild.size();
        }
        
        if((wild[i] == pattern[j]) || (wild[i] == '?')) return solve(wild, pattern, i+1, j+1);
        if(wild[i]=='*')
            return solve(wild, pattern, i+1, j+1) || solve(wild, pattern, i, j+1) || solve(wild, pattern, i+1, j);
        return false;
    }
    bool match(string wild, string pattern)
    {
        return solve(wild, pattern, 0, 0);
    }
};

// recursion with memoization
// https://leetcode.com/problems/wildcard-matching/
class Solution {
public:

    bool solve(string &s, string &p, int i, int j, vector<vector<int> > &dp)
    {
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        if(i==s.size())
        {
            int jj = j;
            while( (j<p.size()) && (p[j] == '*') ) j++;
            dp[i][j] = (j==p.size());
            return dp[i][jj] = dp[i][j];
        }
        
        if((s[i]==p[j]) || (p[j] == '?')) 
            return dp[i][j] = solve(s, p, i+1, j+1, dp);
        if(p[j] == '*')
            return dp[i][j] = (solve(s, p, i, j+1, dp) || solve(s, p, i+1, j, dp) || solve(s, p, i+1, j+1, dp));
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
         vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};