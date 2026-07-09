class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x;
        int ans=-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(1LL*m*m<=x)
            {
                ans=m;
                l=m+1;
            }
            else
            r=m-1;
        }
        return ans;
    }
};