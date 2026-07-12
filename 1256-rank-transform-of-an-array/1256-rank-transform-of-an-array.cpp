class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({arr[i],i});
        sort(v.begin(),v.end());
        vector<int> ans(n);
        int rank=1;
        for(int i=0;i<n;i++)
        {
            if(i>0&&v[i].first!=v[i-1].first)
            rank++;
            ans[v[i].second]=rank;
        }
        return ans;
    }
};