class Solution {
public:
    string longestPalindrome(string s) 
    {
        if ( s.size() <= 1) return s;
        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if(end - start+1 < len)
            {
                start = i -( len -1 )/2;
                end = i + len/2 ;
            }
        }
        return s.substr(start, end-start + 1);
    }
    int expandAroundCenter(string s, int l, int r) 
    {
        while(l>=0 && r<s.size() && s[l]==s[r]) l--, r++;
        return r - l - 1; // note this is minus 1
    }
};
