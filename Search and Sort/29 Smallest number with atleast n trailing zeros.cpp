int cntZero(int n)
{
    int cnt = 0;
    int p = 5;
    while(p <= n)
    {
        cnt += n/p;
        p *= 5;
    }
    return cnt;
}
int findNum(int n)
{
    if(n==1) return 5;
    int l = 0, h = 5*n;
    
    while(l<h)
    {
        int mid = l + (h-l)/2;
        int cnt = cntZero(mid);
        
        if(cnt >= n)
            h = mid;
        else
            l = mid + 1;
    }
    return h;
}