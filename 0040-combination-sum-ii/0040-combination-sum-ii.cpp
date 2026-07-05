class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int n;
    void func(int idx,int target,vector<int>& candidates)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
            continue;
            if(candidates[i]>target)
            break;
            temp.push_back(candidates[i]);
            func(i+1,target-candidates[i],candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        func(0,target,candidates);
        return ans;
    }
};