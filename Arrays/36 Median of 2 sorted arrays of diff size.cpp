// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://www.youtube.com/watch?v=NTop3VTjmxk&ab_channel=takeUforwardtakeUforward
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2 == 0)
        {
            if(n1 % 2) return nums1[n1/2];
            return ( (nums1[n1/2] + (nums1[n1/2 - 1]))/2.0 );
        }
        if(n1 == 0)
        {
            if(n2 % 2) return nums2[n2/2];
            return ( (nums2[n2/2] + (nums2[n2/2 - 1]))/2.0 );
        }
        
        int n = n1 + n2;
        int prev = min(nums1[0], nums2[0]);
        int next = prev;
        
        int i = 0, j = 0;
        int pos = 0, ans;
        while( (i<n1) && (j<n2) && (pos <= n/2) )
        {
            if(nums1[i] < nums2[j]) { prev = next; next = nums1[i]; i++; }
            else { prev = next; next = nums2[j]; j++; }
            pos++;
        }
        while( (pos <= n/2) && (i<n1)) { prev = next; next = nums1[i]; i++; pos++; }
        while( (pos <= n/2) && (j<n2)) { prev = next; next = nums2[j]; j++; pos++; }

        if(n%2) return next;
        return ( (prev + next)/2.0 );
    }
};