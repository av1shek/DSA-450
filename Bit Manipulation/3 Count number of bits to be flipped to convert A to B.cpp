int countBitsFlip(int a, int b){
    int xorr = a ^ b;
    int cnt = 0;
    while(xorr)
    {
        cnt++;
        xorr = xorr & (xorr - 1);
    }
    return cnt;
}