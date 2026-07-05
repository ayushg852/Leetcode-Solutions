class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
int n;
void func(int i,int target,vector<int>& candidates)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    if(i==n)
    return;
    if(candidates[i]<=target)
    {
        temp.push_back(candidates[i]);
        func(i,target-candidates[i],candidates);
        temp.pop_back();
    }
    func(i+1,target,candidates);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        func(0,target,candidates);
        return ans;
    }
};