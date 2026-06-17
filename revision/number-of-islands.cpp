class Solution {
private:
    void dfs(int i, int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int d=0;d<4;d++){
            int nrow=i+drow[d];
            int ncol=j+dcol[d];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return cnt;
    }
};
