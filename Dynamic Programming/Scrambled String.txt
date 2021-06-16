// using ordered map
class Solution {
public:
        map<pair<string, string>, bool> dp;
        bool isScramble( string s1,  string s2) {
        if(s1==s2)
            return 1;
        if(s1 > s2) {
            string t=s2;
            s2 = s1; s1 = t;
        }
        if(dp.find({s1, s2})!=dp.end())  return dp[{s1, s2}];
        
        int len = s1.length();
        
        // additional check
        int count[26] = {0};
        for(int i=0; i<len; i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++){
            if(count[i]!=0)
                return 0;
        }
        // additional check ends here

        for(int i=1; i<=len-1; i++) {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return dp[{s1, s2}] = 1;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return dp[{s1, s2}] = 1;
        }
        return dp[{s1, s2}] = 0;
    }
};

// using unordered map

class Solution {
public:
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
    unordered_map<pair<string, string>, bool, hash_pair> dp;
        bool isScramble( string s1,  string s2) {
        if(s1==s2)
            return 1;
        if(s1 > s2) {
            string t=s2;
            s2 = s1; s1 = t;
        }
        if(dp.find({s1, s2})!=dp.end())  return dp[{s1, s2}];
        
        int len = s1.length();
        
        // additional check
        int count[26] = {0};
        for(int i=0; i<len; i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++){
            if(count[i]!=0)
                return 0;
        }
        // additional check ends here

        for(int i=1; i<=len-1; i++) {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return dp[{s1, s2}] = 1;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return dp[{s1, s2}] = 1;
        }
        return dp[{s1, s2}] = 0;
    }
};