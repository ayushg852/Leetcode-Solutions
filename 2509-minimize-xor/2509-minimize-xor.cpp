class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones=__builtin_popcount(num2);
        int bits=0;
        int copy=num1;
        while(copy>0)
        {
            bits++;
            copy/=2;
        }
        if(ones>=bits)
        return (1<<ones)-1;
        int ans=0;
        int zeros=bits-ones;
        for(int i=bits-1;i>=0;i--)
        {
            if(num1 & (1<<i))
            {
                if(ones>0)
                {
                    ans+=1<<i;
                    ones--;
                }
                else
                zeros--;
            }
            else
            {
                if(zeros==0)
                ans+=1<<i;
                else
                zeros--;
            }
        }
        return ans;
    }
};