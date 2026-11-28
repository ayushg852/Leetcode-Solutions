class Solution {
public:
int func(int i,int t,vector<vector<int>> &dp,vector<int> &nums)
{
    if(t==0)
    return 0;
    if(t<0||i<0)
    return -1e9;
    if(dp[i][t]!=-1)
    return dp[i][t];
    return dp[i][t]=max(func(i-1,t,dp,nums),1+func(i-1,t-nums[i],dp,nums));
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=func(n-1,target,dp,nums);
        if(ans<=0)
        return -1;
        return ans;
    }
};