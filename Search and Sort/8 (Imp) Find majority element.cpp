// Boyer moore
int majorityElement(int arr[], int n)
{
    if(n == 1) return arr[0];
    
    int indx = 0;
    int freq = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] == arr[indx]) freq++;
        else freq--;
        
        if(freq == 0)
        {
            freq = 1;
            indx = i;
        }
    }
    freq = 0;
    for(int i=0;i<n;i++)
        if(arr[i] == arr[indx]) freq++;
    if(freq > n/2)
        return arr[indx];
    return -1;
}