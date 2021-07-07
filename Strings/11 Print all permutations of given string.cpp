class Solution
{
	public:
	    vector<string> ans;
	    void solve( int n, string &s)
	    {
	        if(n == s.size()) 
	        {
	            ans.push_back(s);
	            return;
	        }
	        for(int i=n;i<s.size();i++)
	        {
	            swap(s[n], s[i]);
	            solve(n+1, s);
	            swap(s[n], s[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    string curr;
		    solve( 0, S);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};