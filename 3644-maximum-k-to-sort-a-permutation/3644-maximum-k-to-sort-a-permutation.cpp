class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                if(ans==n)
                ans=nums[i];
                else
                ans&=nums[i];
            }
        }
        return ans==n?0:ans;
    }
};