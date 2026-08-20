class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=1e9+100;
        while(l<=r)
        {
            int m=(l+r)/2;
            int c=1;
            int p=0;
            for(int &x:nums)
            {
                if(x>m)
                {
                    c=k+1;
                    break;
                }
                if(p+x>m)
                {
                    c++;
                    p=x;
                }
                else
                p+=x;
            }
            if(c<=k)
            r=m-1;
            else
            l=m+1;
        }
        return l;
    }
};