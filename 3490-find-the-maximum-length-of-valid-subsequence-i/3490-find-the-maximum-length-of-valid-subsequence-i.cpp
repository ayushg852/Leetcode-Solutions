class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++)
        if(nums[i]&1)
        c++;
        int ans=max(c,n-c);
        if(c>0)
        {
            int p=1;
            int c1=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]%2==p)
                {
                    c1++;
                    p^=1;
                }
            }
            ans=max(ans,c1);
        }
        if(c<n)
        {
            int p=0;
            int c2=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]%2==p)
                {
                    c2++;
                    p^=1;
                }
            }
            ans=max(ans,c2);
        }
        return ans;
    }
};