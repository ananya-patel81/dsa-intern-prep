class Solution {
    bool checkValid(int nr, int nc, int n,vector<vector<int>>& maze,vector<vector<int>>& vis){
        if(nr<0 || nc<0 || nr>=n || nc>=n || maze[nr][nc]==0 || vis[nr][nc]==1){
            return false;
        }
        return true;
    }
    void solve(vector<vector<int>>& maze,vector<vector<int>>& vis, int row, int col,int n, int drow[], int dcol[],vector<string>& ans, string st ){
        if(row==n-1 && col==n-1){
            ans.push_back(st);
            return;
        }
        vis[row][col]=1;
        for(int d=0;d<4;d++){
            int nrow=row+drow[d];
            int ncol=col+dcol[d];
            if(checkValid(nrow,ncol,n,maze,vis)){
                if(d==0){
                    
                    solve(maze,vis,nrow,ncol,n,drow,dcol,ans,st+"D");
                   
                    
                }
                else if(d==1){
                    
                    solve(maze,vis,nrow,ncol,n,drow,dcol,ans,st+"L");
                    
                }
                else if(d==2){
                   
                    solve(maze,vis,nrow,ncol,n,drow,dcol,ans,st+"R");
                    
                }
                else if(d==3){
                    
                    solve(maze,vis,nrow,ncol,n,drow,dcol,ans,st+"U");
                    
                }
            }
        }
        vis[row][col]=0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n=maze.size();
        if(maze[n-1][n-1]==0 || maze[0][0]==0) return {};
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        int drow[]={1,0,0,-1}; //URDL -> DLRU 
        int dcol[]={0,-1,1,0};
        string st="";
        solve(maze,vis,0,0,n,drow,dcol,ans,st);
        return ans;
        
    }
};
