class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int cnt=0;
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^arr[i];
            int remain=xr^k;
            cnt+=mpp[remain];
            mpp[xr]++;
        }
        return cnt;
    }
};
