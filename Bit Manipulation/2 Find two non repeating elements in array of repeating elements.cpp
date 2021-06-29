vector<int> singleNumber(vector<int> nums) 
{
    int n = nums.size();
    int xorr = 0;
    for(int i=0;i<n;i++) xorr = xorr ^ nums[i];
    int cnt = 0;
    while( (xorr&1) == 0)
    {
        cnt++;
        xorr = xorr>>1;
    }
    int a = 0, b = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]&(1<<cnt))
            a = a ^ nums[i];
        else
            b = b ^ nums[i];
    }
    if(a > b) swap(a, b);
    vector<int> ans = {a, b};
    return ans;
}