class Solution {
public:
    bool exp(long long a,int k,int n)
    {
        if(a==0)
        return 0;
        long long r=1;
        while(k>0)
        {
            if(k&1)
            {
                if(r*a>n)
                return 1;
                r*=a;
            }
            k>>=1;
            if(k>0)
            {    
                if(a>n/a)
                return true;
                a*=a;
            }
        }
        return r>n;
    }
    int func(int n,int k)
    {
        if(n<0)
        return 0;
        int l=0;
        int r=n+1;
        int ans=r;
        while(l<=r)
        {
            int m=r-(r-l)/2;
            if(exp(m,k,n))
            {
                ans=m;
                r=m-1;
            }
            else            
            l=m+1;
        }
        return ans;
    }
    int countKthRoots(int l, int r, int k) {
        return func(r,k)-func(l-1,k);
    }
};