// https://leetcode.com/problems/word-break/submissions/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false); dp[0]=true;
        for(int i = 0; i <= s.size(); i++)
        {
            if(dp[i])
                for(auto str: wordDict)
                    if(s.substr(i,str.size()).compare(str)==0)
                        dp[i+str.size()]=true;

        }
        return dp[s.size()];
    }
};