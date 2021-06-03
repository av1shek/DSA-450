vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        vector<int> pos(k, 0);
        for(int i=0;i<k;i++) {
            if(arr[i].size()>0) 
                pq.push( { arr[i][0], i} );
        }
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            pii curr = pq.top(); pq.pop();
            ans.push_back(curr.first);
            int i = curr.second;
            pos[i]++;
            if(pos[i] < k)
                pq.push( { arr[i][pos[i]], i } );
        }
        return ans;
    }