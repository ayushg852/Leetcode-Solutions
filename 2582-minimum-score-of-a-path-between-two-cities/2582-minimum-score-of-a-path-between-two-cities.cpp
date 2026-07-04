class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto v:roads)
        {
            g[v[0]].push_back({v[1],v[2]});
            g[v[1]].push_back({v[0],v[2]});
        }
        queue<int> q;
        q.push(1);
        vector<int> vis(n+1);
        vis[1]=0;
        int ans=1e5;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto [child,w]:g[node])
            {
                ans=min(ans,w);
                if(!vis[child])
                {
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
        return ans;
    }
};