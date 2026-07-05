class Solution {
public:
    vector<vector<int>> subsets;
    int n;
    void func(int i,vector<int> &subset,vector<int> &nums)
    {
        if(i==n)
        {
            subsets.push_back(subset);
            return;
        }
        int j=i+1;
        while(j<n&&nums[j]==nums[i])
        j++;
        func(j,subset,nums);
        for(int count=1;count<=j-i;count++)
        {
            subset.push_back(nums[i]);
            func(j,subset,nums);
        }
        for(int count=1;count<=j-i;count++)
        {
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<int> subset;
        func(0,subset,nums);
        return subsets;
    }
};