ll int maximizeSum(ll arr[], int n, int k)
{
    sort(arr, arr+n);
    int i = 0;
    while(i<n && k>0 && arr[i]<0)
    {
        arr[i] = -1 *arr[i];
        i++;
        k--;
    }
    
    sort(arr, arr+n);
    if(k%2) arr[0] = -arr[0];
    
    ll sum = 0;
    for( i=0;i<n;i++)
        sum += arr[i];
    return sum;
}