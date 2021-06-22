int minSwap(int *a, int n, int k) {
    int cnt=0;
    
    //forming window
    for(int i=0 ;i<n ;i++) if(a[i]<=k) cnt++;
    int bad=0;
    
    //finding value in first window
    for(int j=0 ;j<cnt ;j++) if(a[j]>k) bad++;
    
    //sliding the window
    
    // marking answer fr first window
    int ans=bad;
    for(int i=0,j=cnt ; j<n ;i++,j++){
        
        // observing for next window
        if(a[i]>k) bad--;
        if(a[j]>k) bad++;
        
        ans=min(ans,bad);
    }
    
    return ans;
}