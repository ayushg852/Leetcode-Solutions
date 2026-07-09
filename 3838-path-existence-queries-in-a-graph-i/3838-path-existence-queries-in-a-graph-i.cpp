class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> where(n);
        int cur=0;        
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]>maxDiff)
            cur++;
            where[i]=cur;
        }
        vector<bool> ans;
        for(auto v:queries)
        {
            if(where[v[0]]==where[v[1]])
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};