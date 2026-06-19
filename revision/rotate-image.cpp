class Solution {
private:
    void swapind(int i1,int j1, int i2, int j2, vector<vector<int>>& matrix){
        int temp=matrix[i1][j1];
        matrix[i1][j1]=matrix[i2][j2];
        matrix[i2][j2]=temp;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){//make sure to not do double swapping 
                if(i==j) continue;
                else{
                    swapind(i,j,j,i,matrix);
                }
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

        
    }
};
