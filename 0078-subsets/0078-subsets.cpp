class Solution {
public:
    vector<vector<int>> subsets_ans;
    int n;
    void func(int i,vector<int> &subset,vector<int> &nums)
    {
        if(i==n)
        {
            subsets_ans.push_back(subset);
            return;
        }
        func(i+1,subset,nums);

        subset.push_back(nums[i]);
        func(i+1,subset,nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int> subset;
        func(0,subset,nums);
        return subsets_ans;
    }
};