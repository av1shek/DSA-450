int countRev (string s)
{
    int n = s.size();
    if(n%2 == 1) return -1;
    int oc = 0, cc = 0;
    for(auto ch : s)
    {
        if(ch == '{') oc++;
        else
        {
            if(oc) oc--;
            else cc++;
        }
    }
    return ceil(oc/2.0) + ceil(cc/2.0);
}

// Similar problem 
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int oc = 0, cc = 0;
        for(auto ch : s)
        {
            if(ch == '(') oc++;
            else
            {
                if(oc) oc--;
                else cc++;
            }
        }
        return oc + cc;
    }
};

