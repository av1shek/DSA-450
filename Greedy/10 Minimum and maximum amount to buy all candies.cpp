vector<int> candyStore(int a[], int n, int k)
{
    sort(a, a+n);
    vector<int> ans;
    int cost = 0;
    int i=0, j = n-1;
    while(i<=j)
    {
        cost += a[i];
        i++;
        j -= k;
    }
    ans.push_back(cost);
    cost = 0;
    i = 0, j = n-1;
    while(i<=j)
    {
        cost += a[j];
        j--;
        i += k;
    }
    ans.push_back(cost);
    return ans;
}