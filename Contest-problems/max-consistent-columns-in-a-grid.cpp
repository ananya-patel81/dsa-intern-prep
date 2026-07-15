class Solution {
public:

    bool isValid(vector<vector<int>> &grid, int a, int b, int limit) {
        bool valid = true; 

        for(int i= 0; i < grid.size(); i++) {
            // each row 
            if(abs(grid[i][a] - grid[i][b]) > limit) {
                valid = false; 
                break; 
            }
        }

        return valid; 
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        // maximum no of cols, such that all are valid. 

        // two cols are valid iff for each row |grid[i][b] - grid[i][a]| <= limit 

        // let's check which col pairs are valid 
        int valid[250][250] = {0}; // all invalid 
        int col = grid[0].size(); 
        int row = grid.size(); 

        for(int i = 0; i < col; i++) {
            for(int j = 0; j < i; j++) {
                // if (j, i) is valid or not 
                valid[j][i] = isValid(grid, i, j, limit); 
            }
        }

        // [x1, x2, x3 ... xn] -> maximum valid subsequence... 

        // we can use the dp here. 
        vector<int> dp(col, 1); // each single is valid 
        for(int i= 0; i < col; i++) {
            for(int j = 0; j < i; j++) {
                if(valid[j][i]) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
        }

        // col = state . 
        return *max_element(dp.begin(), dp.end()); 
    }
};
