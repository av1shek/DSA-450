// there are some other approach on gfg, check them too

int minimumNumberOfSwaps(string S)
{
    int left=0,right=0,n=S.size(), ans = 0, fault = 0;
    for(int i=0;i<n;i++) 
    { 
        if(S[i]=='[') 
        { 
            left++;
            if(fault > 0)
            {
                ans += fault;
                fault--;
            }
        }
        else
        {
            right++;
            fault = right - left;
        }
    }
    
    return ans;
}