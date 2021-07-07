class Solution{
    public:
    string ans;
    string removeConsecutiveCharacter(string &s, int i = 0)
    {
        if(i == s.size()) return ans;
        if(i + 1 == s.size())
        {
            ans.push_back(s[i]);
            return ans;
        }
        if(s[i] != s[i+1])
            ans.push_back(s[i]);
        return removeConsecutiveCharacter(s, i+1);
    }
};