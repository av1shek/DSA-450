class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int dx[4] = { -1, 0, +1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid)
    {
        if( x<0 || x>=n) return false;
        if( y<0 || y>=m) return false;
        return (grid[x][y]== -1);
    }

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector< vector<int> > ans(n, vector<int>(m, -1));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1) 
            {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
        int dis = 0;

        while(!q.empty())
        {
            int N = q.size();
            dis++;

            for(int i=0;i<N;i++)
            {
                pair<int, int> curr = q.front(); q.pop();
                int x = curr.first;
                int y = curr.second;
                for(int j=0;j<4;j++)
                {
                    if(isValid(x+dx[j], y+dy[j], n, m, ans))
                    {
                        ans[x+dx[j]][y+dy[j]] = dis;
                        q.push({x+dx[j], y+dy[j]});
                    }
                }
            }
        }
        return ans;
	}
};