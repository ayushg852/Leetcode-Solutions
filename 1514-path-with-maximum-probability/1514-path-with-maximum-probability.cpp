class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> g(n);
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n);
        vector<int> vis(n);
        pq.push({1,start_node});
        dist[start_node]=1;
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            if(vis[node])
            continue;
            vis[node]=1;
            for(auto &[c,w]:g[node])
            {
                if(dist[c]<dist[node]*w)
                {
                    dist[c]=dist[node]*w;
                    pq.push({dist[c],c});
                }
            }
        }
        return dist[end_node];
    }
};