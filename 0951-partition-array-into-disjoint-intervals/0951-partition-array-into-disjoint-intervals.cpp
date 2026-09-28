class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> s(n);
        s[n-1]=nums[n-1];
        for(int i=n-2;i>=1;i--)
        s[i]=min(s[i+1],nums[i]);
        int m=-1;
        for(int i=0;i<n-1;i++)
        {
            m=max(m,nums[i]);
            if(m<=s[i+1])
            return i+1;
        }
        return 0;
    }
};