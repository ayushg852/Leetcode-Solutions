class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void func(int idx,vector<int> &nums)
    {
        if(idx==n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(nums[idx],nums[i]);
            func(idx+1,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        func(0,nums);
        return ans;
    }
};