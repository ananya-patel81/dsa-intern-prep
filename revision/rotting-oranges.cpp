class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        int cntfresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({0,{i,j}}); //{time,{i,j}};
                }
                if(grid[i][j]==1){
                    cntfresh++;
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int tm=0;
        int cnt=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int t=curr.first;
            int r=curr.second.first;
            int c=curr.second.second;
            tm=max(t,tm);
            for(int d=0;d<4;d++){
                int nrow=r+drow[d];
                int ncol=c+dcol[d];
                if(nrow>=0 && ncol>=0 && ncol<n && nrow<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    cnt++;
                    vis[nrow][ncol]=2;
                    q.push({t+1,{nrow,ncol}});
                }
            }


        }

        if(cnt!=cntfresh) return -1;
        return tm;
        
    }
};
