class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int m=logs.back()[1];
        m=max(m,*max_element(queries.begin(),queries.end()));
        vector<int> v(m+x+2);
        vector<int> end(n+1,-1);
        for(auto &ar:logs)
        {
            int id=ar[0];
            int time=ar[1];
            if(time>end[id])
            {
                v[time]--;
                v[time+x+1]++;
                end[id]=time+x+1;
            }
            else
            {
                v[end[id]]--;
                v[time+x+1]++;
                end[id]=time+x+1;
            }
        }
        v[0]=n;
        for(int i=1;i<m+x+2;i++)
        v[i]+=v[i-1];
        vector<int> ans;
        for(auto &q:queries)
        ans.push_back(v[q]);
        return ans;
    }
};