#include <bits/stdc++.h>
using namespace std;

// Class to solve the Rat in a Maze problem
class Solution {
public:
    // Function to check if the cell is within maze and valid to move
    bool validMove(int row, int col,int n,vector<vector<int>> &maze,vector<vector<int>>& vis ){
        if(row>=n||col>=n||row<0||col<0|| vis[row][col]==1||maze[row][col]==0) return false;
        return true;
    }
    
    void validPath(int row,int col,vector<vector<int>> &maze,string current,int n,vector<vector<int>>& vis,vector<string>& res,vector<int>& drow,vector<int>& dcol){
        if(row==n-1 && col==n-1){
            res.push_back(current);
        }
        string direc="DLRU";
        for(int idx=0;idx<4;idx++){
            int nextrow=row+drow[idx];
            int nextcol=col+dcol[idx];
            if(validMove(nextrow,nextcol,n,maze,vis)){
                vis[nextrow][nextcol]=1;
                current.push_back(direc[idx]);
                validPath(nextrow,nextcol,maze,current,n,vis,res,drow,dcol);
                current.pop_back();
                vis[nextrow][nextcol]=0;
            }
        }
        
    }
    

    // Main function to find all paths
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> res;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> drow={+1,0,0,-1}; //D,L,R,U
        vector<int> dcol={0,-1,+1,0};
        validPath(0,0,maze,"",n,vis,res,drow,dcol);
        return res;
        
    }
};

// Driver code
int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    Solution obj;
    vector<string> paths = obj.findPath(maze, n);

    for (auto &p : paths) cout << p << " ";
}
