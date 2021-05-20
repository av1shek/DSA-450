class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int dx[4] = { -1, 0, +1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid)
    {
        if( x<0 || x>=n) return false;
        if( y<0 || y>=m) return false;
        if(grid[x][y] != 1) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==2)
        q.push({i, j});
        
        int cnt = 0;
        
        while(!q.empty())
        {
            int N = q.size();
            cnt++;
            for(int i=0;i<N;i++)
            {
                pair<int, int> curr = q.front(); q.pop();
                
                for(int j=0;j<4;j++)
                {
                    if(isValid(curr.first + dx[j], curr.second+dy[j], n, m, grid))
                    {
                        q.push({curr.first + dx[j], curr.second+dy[j]});
                        grid[curr.first + dx[j]][curr.second + dy[j]] = 2;
                    }
                        
                }
            }
            
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==1) return -1;
        return cnt-1;
    }
};