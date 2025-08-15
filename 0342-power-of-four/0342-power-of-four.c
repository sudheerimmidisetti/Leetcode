bool isPowerOfFour(int n) {
    int x=0,c=4;
    while(n>=pow(c,x)) {
        if(n==pow(c,x))     return true;
        else {
            c=4;
            x++;
        }
    }
    return false;
}