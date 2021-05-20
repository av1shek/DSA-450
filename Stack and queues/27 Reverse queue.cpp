void reverse(queue<int> &q)
{
    if(q.size()<=1) return;
    int x = q.front(); q.pop();
    reverse(q);
    q.push(x);
}
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}