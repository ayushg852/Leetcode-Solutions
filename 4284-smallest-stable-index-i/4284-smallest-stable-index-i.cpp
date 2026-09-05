class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> smin(n,nums[n-1]);
        for(int i=n-2;i>=0;i--)
        smin[i]=min(smin[i+1],nums[i]);
        int p=-1;
        for(int i=0;i<n;i++)
        {
            p=max(p,nums[i]);
            if(p-smin[i]<=k)
            return i;
        }
        return -1;
    }
};