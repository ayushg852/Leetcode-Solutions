class Solution {
public:
    int edge;
    int vertice;
    void dfs(int node,vector<vector<int>> &g,vector<int> &vis)
    {
        vis[node]=1;
        vertice++;
        for(auto &c:g[node])
        {
            edge++;
            if(!vis[c])
            dfs(c,g,vis);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto &v:edges)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> vis(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                edge=0;
                vertice=0;
                dfs(i,g,vis);
                if(edge==(vertice)*(vertice-1))
                ans++;
            }
        }
        return ans;
    }
};