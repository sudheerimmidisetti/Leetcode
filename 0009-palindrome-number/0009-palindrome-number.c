bool isPalindrome(int x) {
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    long long int t = x, rev = 0;
    while (t != 0) {
        rev = rev * 10 + (t % 10);
        t /= 10;
    }
    if (rev == x)
        return true;
    else
        return false;
}