// Approach 1 (Brute force) O(n*n) TLE
#define pii pair<int, int>
int findPlatform(int arr[], int dep[], int n)
{
	vector<pii> timing;
	for(int i=0;i<n;i++) timing.push_back({arr[i], dep[i]});
	sort(timing.begin(), timing.end());

	vector<pii> trains;
	trains.push_back(timing[0]);
	
	for(int i=1;i<n;i++)
	{
	    bool flag = true;
	    for(int j=0;j<trains.size();j++)
	    {
	        int departurePlat = trains[j].second;
	        int arrivalCurr = timing[i].first;
	        
	        if(arrivalCurr > departurePlat)
	        {
	            flag = false;
	            trains[j] = timing[i];
	            break;
	        }
	    }
	    if(flag == true)
	        trains.push_back(timing[i]);
	}

	return trains.size();
}
// Approach 2, efficient O(n)

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr+n);
    sort(dep, dep+n);
    
    int i = 1, j = 0;
    int maxtrains = 1;
    int platform = 1;
    
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            maxtrains++;
            i++;
        }
        
        else{
            maxtrains--;
            j++;
        }
        
        platform = max(platform, maxtrains);
    }
    
      return platform;
}