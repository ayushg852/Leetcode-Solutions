class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<pair<int,int>,int>> v(n);
        for(int i=0;i<n;i++)
        v[i]={{intervals[i][0],intervals[i][1]},i};
        sort(v.begin(),v.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int j=lower_bound(v.begin(),v.end(),make_pair(make_pair(v[i].first.second,-1e7),-1e7))-v.begin();
            ans[v[i].second]=j==n?-1:v[j].second;
        }
        return ans;
    }
};