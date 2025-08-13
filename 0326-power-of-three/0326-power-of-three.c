bool isPowerOfThree(int n) {
    int x = 1;
    while (n >= pow(x, 3) && n > 0) {
        if (n == 1)
            return true;
        else if (n == pow(3, x))
            return true;
        else
            x++;
    }
    
    return false;
}