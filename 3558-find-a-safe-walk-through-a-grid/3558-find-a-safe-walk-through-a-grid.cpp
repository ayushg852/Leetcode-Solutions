class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        deque<pair<int,int>> q;
        q.push_front({0,0});
        vector<vector<int>> d(m,vector<int>(n,1e8));
        d[0][0]=grid[0][0];
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop_front();
            if(i>0&&d[i-1][j]==1e8)
            {
                d[i-1][j]=d[i][j]+grid[i-1][j];
                if(grid[i-1][j])
                q.push_back({i-1,j});
                else
                q.push_front({i-1,j});
            }
            if(i<m-1&&d[i+1][j]==1e8)
            {
                d[i+1][j]=d[i][j]+grid[i+1][j];
                if(grid[i+1][j])
                q.push_back({i+1,j});
                else
                q.push_front({i+1,j});
            }
            if(j>0&&d[i][j-1]==1e8)
            {
                d[i][j-1]=d[i][j]+grid[i][j-1];
                if(grid[i][j-1])
                q.push_back({i,j-1});
                else
                q.push_front({i,j-1});
            }
            if(j<n-1&&d[i][j+1]==1e8)
            {
                d[i][j+1]=d[i][j]+grid[i][j+1];
                if(grid[i][j+1])
                q.push_back({i,j+1});
                else
                q.push_front({i,j+1});
            }
        }
        if(health>d[m-1][n-1])
        return true;
        else
        return false;
    }
};