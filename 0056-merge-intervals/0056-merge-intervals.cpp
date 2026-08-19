class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int l=arr[0][0];
        int r=arr[0][1];
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i][0]>r)
            {
                ans.push_back({l,r});
                l=arr[i][0];
                r=arr[i][1];
            }
            else
            r=max(r,arr[i][1]);
        }
        ans.push_back({l,r});
        return ans;
    }
};