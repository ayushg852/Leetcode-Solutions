class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        while(l<n&&r<n)
        {
            int f=0;
            while(r<n&&nums[r]<=right)
            {
                if(nums[r]>=left&&nums[r]<=right)
                f=1;
                r++;
            }
            if(f==1)
            {
                for(int i=l;i<r;i++)
                {
                    if(nums[i]>=left&&nums[i]<=right)
                    {
                        ans+=(i-l+1)*(r-i);
                        l=i+1;
                    }
                }
            }
            r++;
            l=r;
        }
        return ans;
    }
};