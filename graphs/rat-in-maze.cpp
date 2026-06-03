class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        if(n==1) return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q; //row, col,dist;
        q.push({{0,0},1});
        vis[0][0]=1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                    q.push({{nrow,ncol},step+1});
                    vis[nrow][ncol]=1;

                }
                if(nrow==n-1 && ncol==n-1){
                    return step + 1;
                }
            }
        }

        return -1;
        
    }
};
