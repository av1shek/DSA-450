// also check how to verify given order is correct or not if an order is given
class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int> graph[k];
        for(int i=0;i<n-1;i++)
        {

            string a = dict[i];
            string b = dict[i+1];
            int it1 = 0;
            int it2 = 0;
            while((it1 < a.size()) && (it2 < b.size()) && (a[it1] == b[it2]) )it1++, it2++;
            if((it1 < a.size()) && (it2 < b.size() ) )
                graph[ a[it1] - 'a'].push_back(b[it2] - 'a');

        }
        vector<int> indeg(k, 0);
        for(int i=0;i<k;i++)
            for(auto it:graph[i]) indeg[it]++;
        queue<int> q;
        for(int i=0;i<k;i++)
            if(indeg[i]==0)
                q.push(i);
        string ans;
        
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            ans.push_back( 'a' + curr);
            
            for(auto v: graph[curr]) 
            {
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }
        //cout << ans ;
        return ans;
    }
};