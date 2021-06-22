void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n = arr.size();
        int low = 0, high = n-1;
        for(int i=0;i<=high;)
        {
            if(arr[i] < a) swap(arr[i++], arr[low++]);
            else if( arr[i] > b) swap(arr[i], arr[high--]);
            else i++;
        }
    }