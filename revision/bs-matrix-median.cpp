class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int total=n*m;
        int desired_count= total/2;
        int low=mat[0][0];
        int high=mat[n-1][m-1];
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int ans=low;
        while(low<=high){
            int mid = low+ (high-low)/2; 
            int total_elements_le=0;
            
            for(int i=0;i<n;i++){
                total_elements_le += upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
                
            }
            if(total_elements_le > desired_count){
                ans=mid;
                high=mid-1;
            }
            else{
                //ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};
