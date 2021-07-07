class Solution{
    public:
    static int bitCnt(int n)
    {
        int cnt = 0;
        while(n)
        {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
    static bool comp(int a, int b)
    {
        int aCnt = bitCnt(a);
        int bCnt = bitCnt(b);
        return aCnt > bCnt;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, comp);
    }
};