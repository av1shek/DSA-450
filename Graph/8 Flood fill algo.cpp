class Solution {
public:
    int m, n;
    bool isValid(int x, int y, vector<vector<int>>& image, vector<vector<int>>& vis, int col)
    {
        if(x>=m || y>=n) return false;
        if(x<0 || y<0) return false;
        if(vis[x][y]) return false;
        return image[x][y]==col;
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& image, int x, int y, int nc, int col, vector<vector<int>>& vis)
    {
        vis[x][y] = 1;
        image[x][y] = nc;
        for(int i=0;i<4;i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(isValid(xx, yy, image, vis, col))
                dfs(image, xx, yy, nc, col, vis);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        
        vector<vector<int> > vis(n, vector<int>(n, 0));
        dfs(image, sr, sc, newColor, image[sr][sc], vis);
        return image;
    }
};