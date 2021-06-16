class Solution{
    public:
    int  N;
    bool isValid(int x, int y, vector<vector<int>> &mat)
    {
        if(x>=N || y>=N) return false;
        if(x<0 || y<0) return false;
        
        if(mat[x][y] == 1) return true;
        return false;
    }
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void dfs(int x, int y, vector<vector<int>> &mat, string path, vector<string> &ans)
    {
        if(x==N-1 && y==N-1)
        {
            ans.push_back(path);
            return;
        }
        
        for(int i=0;i<4;i++)
        {
             int xx = x + dx[i];
             int yy = y + dy[i];
             string s = path;
             
             if(i==0) s += 'D'; 
             else if(i==1) s += 'U';   
             else if(i==2) s += 'L';    
             else s += 'R';     
             
             
            if(isValid(xx, yy, mat )) 
            {
                mat[xx][yy] = -1;
                dfs(xx, yy, mat, s, ans);
                mat[xx][yy] = 1;
            }
                
        }
       
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        N = n;
        vector<string> ans;
        if(mat[0][0] == 0) return ans;
        if(mat[n-1][n-1] == 0) return ans;
        
        string s = ""; mat[0][0] = -1;
        dfs(0, 0, mat, s, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }