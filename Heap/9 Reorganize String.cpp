class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for(auto it:s) mp[it]++;
        int maxx = 0;
        char ch;
        for(auto it:mp) if(maxx < it.second ) { maxx = it.second; ch = it.first; }
        int idx = 0;
        if(maxx > ceil(s.size()/2.0)) return "";
        while(mp[ch]>0)
        {
            s[idx] = ch;
            idx += 2;
            mp[ch]--;
        }
        
        for(auto &it:mp)
        {
            while(it.second > 0)
            {
                if(idx >= s.size()) idx = 1;
                s[idx] = it.first;
                it.second--;
                idx += 2;
            }
        }
        return s;
    }
};