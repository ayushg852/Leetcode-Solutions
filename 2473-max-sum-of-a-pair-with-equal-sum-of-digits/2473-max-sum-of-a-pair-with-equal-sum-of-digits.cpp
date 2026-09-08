class Solution {
public:
    int sumDigits(int n)
    {
        int s=0;
        while(n>0)
        {
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int &x:nums)
        m[sumDigits(x)].push_back(x);
        int ans=-1;
        for(auto &[x,v]:m)
        {
            int nn=v.size();
            if(nn==1)
            continue;
            int fmax=0;
            int smax=0;
            for(int i=0;i<nn;i++)
            {
                if(v[i]>=fmax)
                {
                    smax=fmax;
                    fmax=v[i];
                }
                else if(v[i]>smax)
                smax=v[i];
            }
            ans=max(ans,fmax+smax);
        }
        return ans;
    }
};