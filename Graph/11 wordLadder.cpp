class Solution {
public:
    bool isEligible(string a, string b)
    {
        if(a.size() != b.size()) return false;
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) cnt++;
            if(cnt==2) return false;
        }
        return cnt==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int cnt =1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string curr = q.front(); q.pop();
                if(curr == endWord) return cnt;
                for(int i=0;i<wordList.size();i++)
                {
                    if(wordList[i] == "") continue;
                    if(isEligible(curr, wordList[i]))
                    {
                        q.push(wordList[i]);
                        wordList[i] = "";
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};