bool find3Numbers(int a[], int n, int X)
    {
        sort(a, a+n);
        for(int i=0;i<n;i++)
        {
            int x = X - a[i];
            int low = i+1;
            int high = n-1;
            
            while(low < high)
            {
                int sum = a[low] + a[high];
                if(sum > x) high--;
                else if(sum < x) low++;
                else return true;
            }
        }
        return false;
    }