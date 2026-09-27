class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,long>>> g(n);
        for(auto &v:edges)
        {
            g[v[0]].push_back({v[1],v[2]});
            g[v[1]].push_back({v[0],v[2]});
        }
        vector<int> vis(n);
        vector<long> dis(n,1e10);
        set<pair<long,int>> st;
        st.insert({0,0});
        dis[0]=0;
        vector<int> ans(n,-1);
        ans[0]=0;
        while(st.size()>0)
        {
            auto node=*(st.begin());
            int v=node.second;
            st.erase(st.begin());
            if(vis[v])
            continue;
            vis[v]=1;
            for(auto &[c,w]:g[v])
            {
                if(dis[v]+w<dis[c]&&dis[v]+w<disappear[c])
                {
                    dis[c]=dis[v]+w;
                    ans[c]=dis[v]+w;
                    st.insert({dis[c],c});
                }
            }
        }
        return ans;
    }
};