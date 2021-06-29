// https://leetcode.com/problems/maximum-product-subarray/discuss/183483/JavaC%2B%2BPython-it-can-be-more-simple
#define ll long long
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), res = arr[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * arr[i];
            r =  (r ? r : 1) * arr[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
};