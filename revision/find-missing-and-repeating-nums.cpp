class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long sum=0;
        long long sqrsum=0;
        long long total=n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                sqrsum+= (grid[i][j])*(grid[i][j]);
            }
        }

        long long reqdsum=((total)*(total+1))/2;
        long long reqdsqrsum=((total)*(total+1)*(2*total+1))/6;
        int sqrdiff= (int)sqrsum-(int)reqdsqrsum;
        int sumdiff=(int)sum - (int)reqdsum;
        int num=sqrdiff/sumdiff;
        int repeat=(num + sumdiff)/2;
        int miss=(num-sumdiff)/2;
        return {repeat,miss};


        
    }
};
