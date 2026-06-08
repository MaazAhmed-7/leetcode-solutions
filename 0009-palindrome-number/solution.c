bool isPalindrome(int x) {
    int m=x;
    long int temp=0;
    if(x<0){
        return false;
    }
    while(m!=0){
        int d=m%10;
        temp=temp*10+d;
        m/=10;
    }
    if(x==temp){
        return true;
    }
    else{
        return false;
    }
}
