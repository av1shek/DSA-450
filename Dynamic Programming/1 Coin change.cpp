// recursive 
void solve(int s[], int m, int n, int &ans)
{
    if(n==0)
    {
        ans++;
        return;
    }
    if(m<=0 || n<0) return;
    
    for(int i=0; s[m-1]*i <= n; i++ )
        solve(s, m-1, n-(s[m-1]*i), ans);
}

long long int count( int s[], int m, int n )
{
   int ans = 0;
   solve(s, m, n, ans);
  return ans;
}