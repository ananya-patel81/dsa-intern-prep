class Solution {
public:
    vector<int> genRow(int row){
        
        vector<int> ans;
        long long num=1;
        ans.push_back(num);
        for(int col=1;col<row;col++){
            num=num*(row-col);
            num=num/col;
            ans.push_back((int) num);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            temp= genRow(i);
            ans.push_back(temp);
        }

        return ans;
        
    }
};
