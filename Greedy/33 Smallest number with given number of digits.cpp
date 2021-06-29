string smallestNumber(int num, int D){
    if(num > 9*D || num < 1) return "-1";
    string s(D, '0');
    num--;
    s[0] = '1';
    
    for(int i=D-1;i>=1;i--)
    {
        if(num < 9)
        {
            s[i] += num;
            num = 0;
            break;
        }
        else
        {
            s[i] += 9;
            num -= 9;
        }
    }
    if(num) 
        s[0] += num;
    return s;
}