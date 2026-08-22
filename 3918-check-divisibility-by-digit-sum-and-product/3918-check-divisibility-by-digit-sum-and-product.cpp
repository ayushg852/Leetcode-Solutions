class Solution {
public:
    bool checkDivisibility(int n) {
        int c=n;
        int s=0;
        int p=1;
        while(c>0)
        {
            int d=c%10;
            s+=d;
            p*=d;
            c/=10;
        }
        s+=p;
        return n%s==0?true:false;
    }
};