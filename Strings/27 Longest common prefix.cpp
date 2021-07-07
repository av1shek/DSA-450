class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        int pos = 0;
        
        while(true)
        {
            bool flag = true;
            for(int i=1;i<n;i++)
            {
                if(pos == strs[i].size() || strs[i][pos] != strs[0][pos])
                {
                    flag = false;
                    break;
                }
            }
            if(flag) pos++;
            else break;
        }
        return strs[0].substr(0, pos);
    }
};