void sort012(int a[], int n)
{
    int cnt[3] = {0};
    for(int i=0;i<n;i++)
        cnt[a[i]]++;
        
    int i=0;
    for(i=0;i<cnt[0];i++) a[i] = 0;
    for(i=cnt[0];i<cnt[0]+cnt[1];i++)  a[i] = 1;
    for(i=cnt[0]+cnt[1]; i<n; i++) a[i] = 2;
}