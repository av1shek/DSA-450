class Solution{
public:
    int minValue(string s, int k){
        int cnt[26] = {0    };
        
        for(char ch:s)
        {
            cnt[ch - 'a']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++) pq.push(cnt[i]);
        
        while(k && pq.size()>0)
        {
            int x = pq.top(); pq.pop();
            x--; k--;
            if(x) pq.push(x);
        }
        
        int sum = 0;
        while(!pq.empty())
        {
            int x = pq.top(); pq.pop();
            sum += x*x;
        }
        return sum;
    }
};