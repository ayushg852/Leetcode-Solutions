class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int p=1;
        int ans=0;
        while(r<n)
        {
            p*=nums[r];
            while(l<=r&&p>=k)
            p/=nums[l++];
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};