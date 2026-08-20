class Solution {
public:
    int maxDistance(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=1;
        int r=nums.back()-nums.front();
        int ans=1;
        while(l<=r)
        {
            int m=(l+r)/2;
            int c=1;
            int p=nums[0];
            for(int i=1;i<n;i++)
            {
                if(nums[i]-p>=m)
                {
                    p=nums[i];
                    c++;
                }
            }
            if(c>=k)
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