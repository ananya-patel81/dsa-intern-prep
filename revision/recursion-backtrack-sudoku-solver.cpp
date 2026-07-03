class Solution {
    bool isValid(vector<vector<char>>& board, char num, int r, int c){
        for(int i=0;i<9;i++){
            if(board[r][i]==num) return false;
            if(board[i][c]==num) return false;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3]==num) return false;

        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    for(char num='1';num<='9';num++){
                        if(isValid(board,num,r,c)){
                            board[r][c]=num;
                            if(solve(board)){
                                return true;
                            }
                            board[r][c]='.';
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};
