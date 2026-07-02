class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>> (n,vector<bool>(k+1,false))); 
        queue<array<int,3>> q;
        q.push({0,0,0});
        vis[0][0][0]=true;
        int d=0;

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto [r,c,used]=q.front();
                q.pop();

                if(r==m-1 && c==n-1)
                    return d;
                
                for(int i=0;i<4;i++)
                {
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr<0 || nr>=m || nc<0 || nc>=n)
                        continue;

                    int nk=used+grid[nr][nc];
                    if(nk>k || vis[nr][nc][nk])
                        continue;

                    vis[nr][nc][nk]=true;
                    q.push({nr,nc,nk});
                }
            }
            d++;
        }
        return -1;
    }
};