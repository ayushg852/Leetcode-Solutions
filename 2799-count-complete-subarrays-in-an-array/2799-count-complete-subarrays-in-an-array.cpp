class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        unordered_set<int> s;
        for(auto &x:nums)
        s.insert(x);
        int dis=s.size();
        unordered_map<int,int> m;
        while(r<n)
        {
            m[nums[r]]++;
            if(m.size()==dis)
            {
                if(ans==0)
                {
                    while(m.size()==dis)
                    {
                        if(m[nums[l]]==1)
                        m.erase(nums[l]);
                        else
                        m[nums[l]]--;
                        l++;
                    }
                    ans=l*(n-r);
                }
                else
                {
                    while(m.size()==dis)
                    {
                        ans+=n-r;
                        if(m[nums[l]]==1)
                        m.erase(nums[l]);
                        else
                        m[nums[l]]--;
                        l++;
                    }
                }
            }
            r++;
        }
        return ans;
    }
};