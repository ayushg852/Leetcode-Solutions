class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        if(1LL*m*k>n)
        return -1;
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid=(l+r)/2;
            int c=0;
            int p=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]>mid)
                p=0;
                else
                {
                    p++;
                    if(p==k)
                    {
                        c++;
                        p=0;
                    }
                }
            }
            if(c>=m)
            r=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
};