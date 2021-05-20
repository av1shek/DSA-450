void reverse(queue<int> &q, int k)
{
    if(k==0 || q.empty()) return;
    int x = q.front(); q.pop();
    reverse(q, k-1);
    q.push(x);
}
queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    reverse(q, k);
    int cnt = n-k;
    while(cnt--)
     {
         q.push(q.front());
         q.pop();
     }
     return q;
}