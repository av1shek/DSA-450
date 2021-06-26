#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
ll merge(ll arr[], ll low, ll mid, ll high)
{
    int i = low, j = mid+1;
    vector<ll> temp;
    ll inv = 0;
    while(i<=mid && j<=high)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            inv += (mid - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid) 
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++)
    {
        arr[low] = temp[i];
        low++;
    }
    return inv;
}
ll mergeSort(ll arr[], ll low, ll high)
{
    if(low >= high) return 0;
    int mid = (low + high) / 2;
    ll inv = 0;
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid+1, high);
    inv += merge(arr, low, mid, high);
    return inv;
}
ll int inversionCount(ll arr[], ll N)
{
    return mergeSort(arr, 0, N-1);
}

};