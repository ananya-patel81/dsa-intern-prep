class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>> rotten;
        int cntfresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    rotten.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntfresh++;
            }
        }


        int tm=0;
        vector<int> drow={-1,0,+1,0};
        vector<int> dcol={0,1,0,-1};
        int cnt=0;

        while(!rotten.empty()){
            int r=rotten.front().first.first;
            int c=rotten.front().first.second;
            int t=rotten.front().second;
            rotten.pop();
            tm=max(tm,t);
            for(int d=0;d<4;d++){
                int nrow=r+drow[d];
                int ncol=c+dcol[d];
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    rotten.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }

        if(cnt!=cntfresh) return -1;
        return tm; 


        
    }
};
