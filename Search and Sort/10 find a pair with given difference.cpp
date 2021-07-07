bool findPair(int arr[], int n, int diff){
    sort(arr, arr+n);
    for(int i=0;i<n;i++){
        int num = arr[i] + diff;
        if(binary_search(arr+i, arr+n, num))
            return true;
    }
    return false;
}