class Solution {
public:
    vector<vector<int>> permutations;
    void func(multiset<int> &s,vector<int> &permutation)
    {
        if(s.empty())
        {
            permutations.push_back(permutation);
            return;
        }
        for(auto it=s.begin();it!=s.end();)
        {
            int value=*it;
            permutation.push_back(value);
            s.erase(it);
            func(s,permutation);
            permutation.pop_back();
            s.insert(value);
            it=s.upper_bound(value);            
        }        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        multiset<int> s(nums.begin(),nums.end());
        vector<int> permutation;
        func(s,permutation);
        return permutations;
    }
};