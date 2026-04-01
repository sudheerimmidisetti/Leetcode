bool isValid(char* s) {
    char st[10001];
    long long int top=-1;
    if(strlen(s)==1)        return false;
    for (long long i=0; i<strlen(s); i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            top++;
            st[top]=s[i];
        }
        else if(top==-1)         return false;
        else if((s[i]==')' && st[top]=='(') || (s[i]=='}' && st[top]=='{') || (s[i]==']' && st[top]=='[')) {
            top--;
        }
        else            return false;
    }
    return top==-1;
}