class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> ps(n+1);
        for(int i=0;i<n;i++)
        ps[i+1]=ps[i]+nums[i];
        long long ans=1e12;
        for(int i=0;i<n;i++)
        {
            long long a=ps[i];
            a+=ps[n]-ps[i]-1LL*(n-i)*nums[i];
            ans=min(ans,a);
        }
        return ans;
    }
};