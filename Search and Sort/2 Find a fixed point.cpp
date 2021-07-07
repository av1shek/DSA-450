class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int> ans;
	    for(int i=1;i<=n;i++)
	    {
	        if(arr[i-1] == i)
	            ans.push_back(i);
	    }
	    return ans;
	}
};