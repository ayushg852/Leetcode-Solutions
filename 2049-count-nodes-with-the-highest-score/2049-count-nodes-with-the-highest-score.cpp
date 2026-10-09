class Solution {
public:
    void dfs(int node,vector<vector<int>> &g,vector<int> &st)
    {
        int s=1;
        for(auto &c:g[node])
        {
            dfs(c,g,st);
            s+=st[c];
        }
        st[node]=s;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> g(n);
        for(int i=1;i<n;i++)
        g[parents[i]].push_back(i);
        vector<int> st(n);
        dfs(0,g,st);
        int c=1;
        long long m=1;
        for(auto &c:g[0])
        m*=st[c];
        for(int i=1;i<n;i++)
        {
            long long p=n-st[i];
            for(auto &c:g[i])
            p*=st[c];
            if(p>m)
            {
                m=p;
                c=1;
            }
            else if(p==m)
            c++;
        }
        return c;
    }
};