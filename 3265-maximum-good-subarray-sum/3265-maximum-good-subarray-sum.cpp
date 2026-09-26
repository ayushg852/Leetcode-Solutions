class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> ps(n+1);
        for(int i=0;i<n;i++)
        ps[i+1]=ps[i]+nums[i];
        unordered_map<int,int> m;
        long long ans=-1e18;
        for(int i=0;i<n;i++)
        {
            if(m.count(0LL+nums[i]-k))
            ans=max(ans,ps[i+1]-ps[m[0LL+nums[i]-k]]);
            if(m.count(0LL+nums[i]+k))
            ans=max(ans,ps[i+1]-ps[m[0LL+nums[i]+k]]);
            if(m.find(nums[i])==m.end()|| ps[i]-ps[m[nums[i]]]<=0)
            m[nums[i]]=i;
        }
        return ans==-1e18?0:ans;
    }
};