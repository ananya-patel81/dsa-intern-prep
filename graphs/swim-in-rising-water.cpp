class Solution {
private:
    bool isValid(int row,int col,int n, int m){
        return (row>=0 && col>=0 && row<n && col<m);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; //minheap;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int depth=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(n-1==r && n-1==c) return depth;
            for(int i=0;i<4;i++){
                int adjrow=r+dr[i];
                int adjcol=c+dc[i];
                if(isValid(adjrow,adjcol,n,n) && vis[adjrow][adjcol]!=1){
                    vis[adjrow][adjcol]=1;
                    pq.push({max(depth,grid[adjrow][adjcol]),{adjrow,adjcol}});
                }
            }
            
        }

        return -1;
        
    }
};
