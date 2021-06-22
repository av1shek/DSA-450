long long mod = 1e9 + 7;
long long countWays(int n, int k){
   if (n == 0) 
        return 0;
    long long same = 0, diff = k;
    long res = same + diff;
    for (int i = 2; i <= n; ++i) {
        same = diff%mod;
        diff = ( res * (k - 1) )%mod;
        res = (same + diff)%mod;
    }
    return res;
}