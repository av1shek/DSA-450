string add(string a, string b)
{
    int carry = 0;
    int i = a.size()-1, j = b.size()-1;
    string s = "";
    while( (i>=0) && (j>=0))
    {
        int val = a[i] - '0' + b[j] - '0' + carry;
        s = char( '0' + val%10) + s;
        carry = val/10;
        i--; j--;
    }
    
    while(i>=0)
    {
        int val = a[i] - '0' + carry;
        s = char( '0' + val%10) + s;
        carry = val/10;
        i--; 
    }
    
    while(j>=0)
    {
        int val = b[j] - '0' + carry;
        s = char( '0' + val%10) + s;
        carry = val/10;
        j--;
    }
    
    if(carry)
        s = to_string(carry) + s;
    return s;
}

string solve(int arr[], int n) {
    int cnt[10] = {0};
    for(int i=0;i<n;i++) cnt[arr[i]]++;
    string a = "", b = "";
    int flag = 1;
    for(int i=1;i<10;i++)
    {
        while(cnt[i]--)
        {
            if(flag) a += to_string(i);
            else b += to_string(i);
            flag = 1 - flag;
        }
    }
    string s = add(a, b);
    return s;
 }