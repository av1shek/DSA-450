void mul(vector<int> &ans, int x)
{
    int carry = 0;
    for(int i=0;i<ans.size();i++)
    {
        int temp = x*ans[i] + carry;
        ans[i] = temp%10;
        carry = temp/10;
    }
    while(carry)
    {
        ans.push_back(carry%10);
        carry = carry/10;
    }
}
vector<int> factorial(int n)
{
    vector<int> ans = {1};
    for(int i=2;i<=n;i++)
        mul(ans, i);
    reverse(ans.begin(), ans.end());
    return ans;
}