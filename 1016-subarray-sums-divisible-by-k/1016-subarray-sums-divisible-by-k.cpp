class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int s=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(auto &x:nums)
        {
            s+=x;
            int f=((s%k)+k)%k;
            if(m.count(f))
            ans+=m[f];
            m[f]++;
        }
        return ans;
    }
};