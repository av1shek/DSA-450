#define pii pair<int, int>
class Solution 
{
    int n;
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8] = {-1, -1, 1 , 1, -2, -2, 2, 2};
    int dy[8] = {-2, 2 , -2, 2, -1,  1, -1, 1};
    bool isValid(int x, int y,  vector<vector<int> > &vis)
    {
        if(x<0 || y<0) return false;
        if(x>=n || y>=n) return false;
        if(vis[x][y] == 1) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&start,vector<int>&end,int N)
	{
	    n = N;
	    int cnt = 0;
	    queue<pii> q;
	    
	    int x = start[0]-1;
	    int y = start[1]-1;
	    
	    q.push( {x, y} );
	    vector<vector<int> > vis(n, vector<int>(n, 0));
	    
	    vis[x][y] = 1;
	    while(!q.empty())
	    {
	        int sz = q.size();
	        for(int i=0;i<sz;i++)
	        {
	            pii curr = q.front(); q.pop();
    	        x = curr.first;
    	        y = curr.second;
    	        if( (end[0]==x+1 ) && (end[1] == y+1) ) return cnt;
    	       
    	        for(int j=0;j<8;j++)
    	        {
    	            int xx = x + dx[j];
    	            int yy = y + dy[j];
    	            
    	            if(isValid(xx, yy, vis))
    	            {
    	                vis[xx][yy] = 1;
    	                q.push({xx, yy});
    	            }
    	        }
	        }
	        cnt++;
	    }
	    return -1;
	}
};