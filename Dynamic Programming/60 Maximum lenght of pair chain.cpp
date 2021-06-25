// O(n^2) linear search
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> ans(n+1, 1);
        for(int i=n-2; i>=0; i--)
        {
            int j = i+1;
            while(j<n && pairs[i][1] >= pairs[j][0]) j++;
            
            if(j==n)
                ans[i] = ans[i+1];
            else
                ans[i] = max(ans[i+1], 1 + ans[j]);
        }
        return ans[0];
    }
};

// O(nlogn) binary search

class Solution {
public:
    int binarySearch(vector<vector<int>> &pairs, int low, int high, int val)
    {
        while(low <= high)
        {
            if(low == high)
            {
                if(pairs[high][0] <= val) return high+1;
                return high;
            }
            int mid = (low + high) / 2;
            
            if(pairs[mid][0] <= val) low = mid+1;
            else high = mid-1;
        }
        
        return high+1;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> ans(n+1, 1);
        for(int i=n-2; i>=0; i--)
        {          
            int j = binarySearch(pairs, i+1, n-1, pairs[i][1]);
            if(j==n)
                ans[i] = ans[i+1];
            else
                ans[i] = max(ans[i+1], 1 + ans[j]);
        }
        return ans[0];
    }
};

// O(nlog n) No searching only greedy
int findLongestChain(vector<vector<int>>& pairs) 
{
    sort(pairs.begin(), pairs.end());
    int n = pairs.size();
    int prev = pairs[0][1];
    int ans = 1;

    for(auto pair : pairs)
    {
        if(pair[0] > prev)
        {
            ans++;
            prev = pair[1];
        }
        else
            prev = min(prev, pair[1]);
    }
    return ans;
}