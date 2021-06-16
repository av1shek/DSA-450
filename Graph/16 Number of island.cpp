class Solution
{
    public:
    int n, m;
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '#';
        for(int it = 0;it<8;it++)
        {
            int x = i+dx[it];
            int y = j+dy[it];

            if( (x>=0) && (y>=0) && (x<m) && (y<n) && (grid[x][y]=='1') )
                dfs(grid, x, y);
        }
    }
    int numIslands(vector<vector<char>> &grid) 
    {
        m = grid.size();
        n = grid[0].size();
        
        int cnt = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    cnt++;
                }
        return cnt;
    }
};