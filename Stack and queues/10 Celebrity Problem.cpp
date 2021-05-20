class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {

       stack<int> s; 
       for(int i=0;i<n-1;i++) s.push(i);
       int a = n-1;
       
       while(!s.empty())
       {
           int b = s.top(); s.pop();
           if(M[a][b]) a = b;
       }
       
       for(int i=0;i<n;i++) if(M[a][i]) return -1;
       for(int i=0;i<n;i++) 
       {
           if(i==a) continue;
           if(M[i][a] == 0) return -1;
       }
        return a;
    }
};