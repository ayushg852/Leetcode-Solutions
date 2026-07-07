class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0,s=0;
        long long power=1;
        while(n>0)
        {
            int d=n%10;
            if(d)
            {
                x+=d*power;
                s+=d;
                power*=10;
            }
            n/=10;
        }
        return s*x;
    }
};