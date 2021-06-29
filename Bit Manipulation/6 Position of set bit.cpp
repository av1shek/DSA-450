int findPosition(int N) 
{
    if((N & (N -1)) or (N == 0)) return -1;
    return log2(N) + 1;
}