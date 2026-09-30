class Solution {
public:
    int ans=0;
    int dfs(int node,int p,vector<vector<int>> &g)
    {
        vector<int> v;
        for(auto &c:g[node])
        {
            if(c==p)
            continue;
            v.push_back(dfs(c,node,g));
        }
        int a=1;
        if(v.size()>0)
        a+=v[0];
        int f=1;
        for(int i=1;i<v.size();i++)
        {
            a+=v[i];
            if(v[i]!=v[i-1])
            f=0;
        }
        if(f)
        ans++;
        return a;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> g(n);
        for(auto &v:edges)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        dfs(0,-1,g);
        return ans++;
    }
};