class Solution {
  public:
    int countSquares(long long n) {
        int l = 0, h = n;
        long long ans = h;
        
        while(l < h)
        {
            long long mid = l + (h-l)/2;
            
            if(mid*mid >= n)
                h = mid;
            else
                l = mid + 1;
        }
        return h - 1;
    }
};


// https://leetcode.com/problems/sqrtx/
// floor(sqrt(x))
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return x;
        int ans = 0, l = 1, h = x;
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            
            if( mid <= x/mid)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid- 1;
        }
        return ans;
    }
};