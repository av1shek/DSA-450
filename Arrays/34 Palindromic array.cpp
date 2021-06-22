int rev(int n)
{
    int temp = 0;
    while(n)
    {
        temp = temp*10 + n%10;
        n = n/10;
    }
    return temp;
}
int PalinArray(int a[], int n)
{  
    for(int i=0;i<n;i++)
        if( rev(a[i]) != a[i]) return 0;
    return 1;
}