class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int p=nums[0]+1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<p)
            ans+=p-nums[i];
            p=max(p+1,nums[i]+1);
        }
        return ans;
    }
};