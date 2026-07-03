class Solution {
    void solve(vector<string>& board,vector<vector<string>>& ans, int col,vector<int>& leftrow,vector<int>& upperdiag,vector<int>& lowerdiag,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && upperdiag[n-1+col-row]==0 && lowerdiag[row+col]==0){
                leftrow[row]=1;
                upperdiag[n-1+col-row]=1;
                lowerdiag[row+col]=1;
                board[row][col]='Q';
                solve(board,ans,col+1,leftrow,upperdiag,lowerdiag,n);
                board[row][col]='.';
                leftrow[row]=0;
                upperdiag[n-1+col-row]=0;
                lowerdiag[row+col]=0;

            }
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        //we need permutations mainly
        vector<string> board;
        vector<vector<string>> ans;
        string temp(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(temp);
        }
        vector<int> leftrow(n,0), upperdiag(2*n-1,0), lowerdiag(2*n-1,0);
        solve(board,ans,0,leftrow,upperdiag,lowerdiag,n);
        return ans;
    }
};
