int doUnion(int a[], int n, int b[], int m)  {
    int cnt = m+n;
    sort(a, a+n);
    sort(b, b+m);
    int i = 0, j = 0;
    while( i<n && j<m)
    {
        if( (i+1 < n) && (a[i] == a[i+1]) ) i++, cnt--;
        else if( (j+1 < m) && (b[j] == b[j+1]) ) j++, cnt--;
        else if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else
        {
            cnt--;
            i++;j++;
        }
    }
    while(i<n)
    {
        if(i+1 < n && a[i]==a[i+1]) cnt--;
        i++;
    }
    while(j<m)
    {
        if(j+1 < m && b[j]==b[j+1]) cnt--;
        j++;
    }
    return cnt;
}