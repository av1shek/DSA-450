// https://youtu.be/g6OxU-hRGtY
int greatestPowerof2(int n)
{
    int i = 0;
    while( (1<<i) <= n) i++;
    return i-1;
}
ll countSetBits(ll n)
{
    if(n<=1) return n;
    ll x = greatestPowerof2(n);
    return (x*(1<<(x-1)) + (n - (1<<x) + 1) + countSetBits(n - (1<<x) ) ) ;
}