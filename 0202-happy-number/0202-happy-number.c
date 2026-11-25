bool isHappy(int n) {
    long long k=0,num=0;
    while(num!=1 && num!=4) {
        num=0;
        while(n>0) {
            k=n%10;
            num+=pow(k,2);
            n/=10;
        }
        n=num;
    }
    if(num==1)      return true;
    else            return false;
}