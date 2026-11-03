class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++)
        x^=nums[i];
        int a=(1<<maximumBit)-1;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            ans[n-1-i]=(x&a)^a;
            x^=nums[i];
        }
        return ans;
    }
};