class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a;
        if(n&1)
        a=nums[n/2];
        else
        a=(nums[n/2-1]+nums[n/2])/2;
        int ans=0;
        for(int i=0;i<n;i++)
        ans+=abs(a-nums[i]);
        return ans;
    }
};