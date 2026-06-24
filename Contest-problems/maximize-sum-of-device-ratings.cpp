class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size();
        int n=units[0].size();
        long long total=0;
        if(n==1){
            for(int i=0;i<m;i++){
                total+=units[i][0];
            }
            return total;
        }
        
        int globalMin=INT_MAX;
        int bestsecondmin=INT_MAX;
        
        for(int i=0;i<m;i++){
            sort(units[i].begin(),units[i].end());
            int a=units[i][0];
            int b= (units[i].size()>1) ? units[i][1] : 0;
            total+=max(a,b);
            globalMin=min(globalMin,a);
            bestsecondmin=min(bestsecondmin,b);
            
        }

        

        return total-bestsecondmin+globalMin;
    }
};
