class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> q;
        for(int i=0;i<k;i++)
        q.insert(nums[i]);
        vector<int> ans;
        ans.push_back(*q.rbegin());
        for(int i=k;i<nums.size();i++)
        {
            auto it=q.find(nums[i-k]);
            q.erase(it);
            q.insert(nums[i]);
            ans.push_back(*q.rbegin());
        }
        return ans;
    }
};