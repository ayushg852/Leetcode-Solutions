class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i==nums.size()||nums[i]!=target)
        return {-1,-1};
        int j=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        j--;
        return {i,j};
    }
};