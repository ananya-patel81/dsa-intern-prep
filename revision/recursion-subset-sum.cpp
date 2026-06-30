class Solution {
  private:
    void helper(vector<int>& sums, int i,int currsum, vector<int>& arr, int n){
        if(i==n){
            sums.push_back(currsum);
            return;
        } 
        helper(sums,i+1,currsum,arr,n);
        helper(sums,i+1,currsum+arr[i],arr,n);
        
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        int n=arr.size();
        vector<int> sums;
        helper(sums,0,0,arr,n);
        return sums;
        
    }
};
