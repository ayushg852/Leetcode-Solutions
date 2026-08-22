class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto &x:nums)
        m[x]--;
        multiset<pair<int,int>> st;
        for(auto &[i,j]:m)
        {
            st.insert({j,i});
            if(st.size()>k)
            st.erase(prev(st.end()));
        }
        vector<int> ans;
        for(auto &i:st)
        ans.push_back(i.second);
        return ans;
    }
};