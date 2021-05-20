vector<long long> nextLargerElement(vector<long long> arr, int n){
        if(arr.size() == 0) return arr;
        
        vector<long long> ans(n, -1);
        
        stack<long long> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty()) {
                s.push(arr[i]);
                continue;
            }
            
            while( (!s.empty()) && (s.top() <= arr[i]) ) s.pop();
            if(!s.empty()) ans[i] = s.top();
            s.push(arr[i]);
        }
        return ans;
    }