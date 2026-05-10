class Solution {
public:
    vector<int> genRow(int row){
        int ans=1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        for(int col=1; col<row; col++){
            ans= ans*(row-col);
            ans= ans/col;
            ansRow.push_back(ans);
        }
        return ansRow;
    };
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i=1; i<=numRows; i++){
            vector<int> temp;
            temp = genRow(i);
            answer.push_back(temp);

        }
        return answer;
        
    }
};
