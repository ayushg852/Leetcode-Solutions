class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> prefix(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            prefix[i][j]=mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=1;i<=m;i++)
        {
            int a=max(1,i-k);
            int c=min(m,i+k);
            for(int j=1;j<=n;j++)
            {                
                int b=max(1,j-k);
                int d=min(n,j+k);
                ans[i-1][j-1]=prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1];
            }
        }
        return ans;
    }
};