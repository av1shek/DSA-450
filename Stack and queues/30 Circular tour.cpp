 int tour(petrolPump p[],int n)
    {
       int indx = 0, sum = 0;
       bool flag = true;
       
       for(int i=0;i<n;i++)
       {
           sum += p[i].petrol - p[i].distance;
           if( sum < 0) 
           {
               indx = i+1;
               sum = 0;
           }
       }
       
       if(indx == n) return -1;
       
       int cnt = n, i = indx;
       sum = 0;
       while(cnt--)
       {
           sum += p[i%n].petrol - p[i%n].distance;; i++;
           if(sum <0) return -1;
       }
       return indx;
    }