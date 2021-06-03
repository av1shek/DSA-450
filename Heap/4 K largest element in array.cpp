vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int sz = k;
    vector<int> ans(sz);    sz--;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    while(!pq.empty()){
        ans[sz--] = pq.top() ;
        pq.pop();
    }
    return ans;
}