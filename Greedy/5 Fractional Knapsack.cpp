static bool comp(Item &a, Item &b)
{
    return (float(a.value)/float(a.weight) ) > ( float(b.value) / float(b.weight));
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, comp);
    int i=0;
    double profit = 0;
    for( i=0;i<n;i++)
    {
        if(arr[i].weight <= W)
        {
            W -= arr[i].weight;
            profit += arr[i].value;
        }
        else
            break;
    }
    
    if(i<n && W>0)
        profit += ( float(arr[i].value)/float(arr[i].weight) ) * W;
    return profit;
}