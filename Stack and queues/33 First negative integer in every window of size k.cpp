vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) 
{
    queue<long long> q;
    vector<long long> ans;
    for(int i=0;i<K-1;i++)
        if(A[i] < 0) q.push(i);
    int j =0;
    for(int i=K-1;i<N;i++, j++)
    {
        if(A[i] < 0) q.push(i);
        if(q.empty()) ans.push_back(0);
        else ans.push_back(A[q.front()]);
        if((!q.empty()) && q.front() == j) q.pop(); 
    }
    return ans;
}