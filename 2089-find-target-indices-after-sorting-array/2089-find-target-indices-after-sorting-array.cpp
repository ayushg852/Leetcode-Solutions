class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c1=0;
        int c2=0;
        for(auto &x:nums)
        {
            if(x==target)
            c1++;
            else if(x<target)
            c2++;
        }
        if(c1==0)
        return {};
        vector<int> ans;
        for(int i=c2;i<c1+c2;i++)
        ans.push_back(i);
        return ans;
    }
};