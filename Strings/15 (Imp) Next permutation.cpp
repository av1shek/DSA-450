class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        int maxx = INT_MIN;
        int i, indx = -1;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] < maxx)
            {
                indx = i;
                break;
            }
            maxx = max(maxx, arr[i]);
        }
        if(indx == -1)
        {
            sort(arr.begin(), arr.end());
            return arr;
        }
        
        int minIndx = indx;
        for(int i=indx+1;i<n;i++)
        {
            if( (arr[i] > arr[indx]) && (arr[i] <= maxx) )
            {
                maxx = arr[i];
                minIndx = i;
            }
        }
        swap(arr[indx], arr[minIndx]);
        sort(arr.begin() + indx + 1, arr.end());
        return arr;
    }
};