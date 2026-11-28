class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int mxel=*max_element(nums.begin(),nums.end());
        vector<vector<int>> factor(mxel+1);
        for(int i=2;i<=mxel;i++)
        {
            if(factor[i].size()>0)
            continue;
            for(int j=i;j<=mxel;j+=i)
            factor[j].push_back(i);
        }
        unordered_map<int,int> m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<n)
        {
            for(int i=0;i<factor[nums[r]].size();i++)
            m[factor[nums[r]][i]]++;
            while(m.size()>k)
            {
                for(int i=0;i<factor[nums[l]].size();i++)
                {
                    if(m[factor[nums[l]][i]]==1)
                    m.erase(factor[nums[l]][i]);
                    else
                    m[factor[nums[l]][i]]--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};