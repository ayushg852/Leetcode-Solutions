class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> d(m,vector<int>(n,1e8));
        deque<pair<int,int>> q;
        q.push_front({0,0});
        d[0][0]=0;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(!q.empty())
        {
            auto [oi,oj]=q.front();
            q.pop_front();
            for(int i=0;i<4;i++)
            {
                int ni=oi+dr[i];
                int nj=oj+dc[i];
                if(ni<0||ni>=m||nj<0||nj>=n||d[ni][nj]!=1e8)
                continue;
                if(grid[ni][nj])
                {
                    q.push_back({ni,nj});
                    d[ni][nj]=d[oi][oj]+1;
                }
                else
                {
                    q.push_front({ni,nj});
                    d[ni][nj]=d[oi][oj];
                }
            }
        }
        return d[m-1][n-1];
    }
};