class Solution {
public:
    int smallestNumber(int n, int t) {
        int copy=n;
        int p=1;
        while(copy>0)
        {
            p*=copy%10;
            copy/=10;
        }
        if(n%10!=0)
        p/=(n%10);
        while(n%10!=0)
        {
            int c=p*(n%10);
            if(c%t==0)
            return n;
            n++;
        }
        return n;
    }
};