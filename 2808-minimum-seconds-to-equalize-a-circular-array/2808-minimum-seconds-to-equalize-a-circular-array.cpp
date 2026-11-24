class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        m[nums[i]].push_back(i);
        int ans=n+5;
        for(auto &[x,v]:m)
        {
            int nn=v.size();
            int a=ceil((v[0]+n-1-v[nn-1])/2.0);
            for(int i=1;i<nn;i++)
            a=max(a,(int)ceil((v[i]-v[i-1]-1)/2.0));
            ans=min(ans,a);
        }
        return ans;
    }
};