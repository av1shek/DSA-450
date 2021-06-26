vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i = 0, j= 0, k = 0;
    vector<int> ans;
    while( (i<n1) && (j<n2) && (k<n3))
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            if( (ans.size() ==0) || (a[i]!=ans.back()) )
                ans.push_back(a[i]);
            i++, j++, k++;
        }
        else if( (a[i]<=b[j]) && (a[i]<=c[k]) ) i++;
        else if( (b[j]<=a[i]) && (b[j]<=c[k]) ) j++;
        else if( (c[k]<=a[i]) && (c[k]<=b[j]) ) k++;
    }
    return ans;
}