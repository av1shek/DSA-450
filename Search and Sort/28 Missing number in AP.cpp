int inSequence(int a, int b, int c){
    if(c == 0) return a==b;
    return ( (b-a)%c == 0) && ((b-a)/c >= 0);
}