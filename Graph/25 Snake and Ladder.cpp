class Solution {
public:
    int n;
    int next(int pos, vector<bool> &vis, vector<vector<int>>& board)
    {
        int origPos = pos;
        if(pos > n*n -1)
        return -1;
        int row = pos / n;
        pos = pos%n;
        int col;
        if(row%2) col = n - pos -1;
        else col = pos ;
        if(board[n - 1 - row][col] == -1) return origPos;
        return board[n - 1 - row][col] - 1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int sz = n*n, cnt = 0;
        vector<bool> vis(sz, false);
        queue<int> q; q.push(0); vis[0] = true;
        int dest = sz - 1;


        while(!q.empty())
        {
            int N = q.size();
            for(int i=0;i<N;i++)
            {
                int u = q.front(); q.pop();
                if(u == dest) return cnt;
                for(int x = 1; x<= 6; x++)
                {
                    int v = next(u+x, vis, board);
                    if( (v == -1) || vis[v])  continue; 
                    vis[v] = true;
                    q.push(v);
                }
            }
            cnt++;
        }
        return -1;
    }
};