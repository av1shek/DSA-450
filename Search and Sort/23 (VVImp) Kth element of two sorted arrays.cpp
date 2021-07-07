// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/1321078/median-using-kth-minimum-element-c-olog-n-explained-from-scratch
// https://youtu.be/nv7F4PiLUzo
class Solution{
    public:
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low = 0, high = min(n, k), indx;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int x = mid;
            int y = k - mid;  // x + y == k
            
            int A = ( x>0 )  ? arr1[x-1] : INT_MIN ;
            int B = ( y <= m )  ? arr2[y-1] : INT_MAX ;
            int C = ( x+1 <= n) ? arr1[x] : INT_MAX ;
            int D = ( y+1 <= m) ? arr2[y] : INT_MAX ;

            // ---------A     C---------
            // ---------B     D---------
            
            if( (A<=D) && (B<=C) )
            {
                indx = mid;
                break;
            }
            else if( A > D )
                high = mid - 1;
            else 
                low = mid + 1;
        }
        int ans;
        if(indx <= n)
        {
            int a = arr1[indx - 1];
            int b = arr2[k - indx - 1];
            return max(a, b);
        }
        return arr2[ k - indx - 1];
    }
};