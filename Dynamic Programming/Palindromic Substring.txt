// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// https://leetcode.com/problems/palindrome-partitioning-ii/
// https://leetcode.com/problems/palindrome-partitioning-ii/discuss/1267712/Multiple-Approach-(-Best-solution-)
// Approach 1 (TLE on leetcode)
bool isPalindrome(int i, int j, string &s)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}
int solve(vector<vector<int>> &dp, int i, int j, string &s)
{
    if(i>=j) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    if( isPalindrome(i, j, s) ) return 0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
        ans = min(ans, solve(dp, i, k, s) + solve(dp, k+1, j, s) + 1);
    
    return dp[i][j] = ans;
}
int minCut(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(dp, 0, n-1, s);
}

// Approach2 (optimisation to check palindrome)
class Solution {
public:
bool isPalindrome(vector<vector<int>> &pdp, int i, int j, string &s)
{
    if(i>j) return 1;
    if(i==j) return pdp[i][j] = 1;
    if(pdp[i][j] != -1) return pdp[i][j];
    if(s[i] != s[j]) return pdp[i][j] = 0;
    pdp[i][j] =  isPalindrome(pdp, i+1, j-1, s) ;
    return pdp[i][j];
}
int solve(vector<vector<int>> &dp, int i, int j, string &s, vector<vector<int>> &pdp)
{
    if(i>=j) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    if( pdp[i][j] == 1 ) return dp[i][j] = 0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
        if(pdp[i][k])
             ans = min(ans, solve(dp, i, k, s, pdp) + solve(dp, k+1, j, s, pdp) + 1);
    
    return dp[i][j] = ans;
}
int minCut(string s) 
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> pdp(n, vector<int>(n, -1));
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            isPalindrome(pdp, i, j, s);
    return solve(dp, 0, n-1, s, pdp);
}
};

// Approach 3 (Best Approach - expand along middle)
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
 