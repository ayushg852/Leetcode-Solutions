class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0]=-1;
        int p=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
            p++;
            else
            p--;
            if(m.count(p))
            ans=max(ans,i-m[p]);
            else
            m[p]=i;
        }
        return ans;
    }
};