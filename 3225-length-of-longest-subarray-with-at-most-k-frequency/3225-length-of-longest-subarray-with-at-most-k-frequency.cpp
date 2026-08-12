class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> m;
        while(j<n)
        {
            m[nums[j]]++;
            if(m[nums[j]]>k)
            {
                while(nums[i]!=nums[j])
                m[nums[i++]]--;
                m[nums[i++]]--;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};