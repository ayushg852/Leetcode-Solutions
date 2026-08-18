class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)
        return 0;
        int a=INT_MAX;
        int sign=x>=0?1:-1;
        x=abs(x);
        int n=0;
        while(x>0)
        {
            if(n>a/10)
            return 0;
            n=n*10+x%10;
            x/=10;
        }
        return n*sign;
    }
};