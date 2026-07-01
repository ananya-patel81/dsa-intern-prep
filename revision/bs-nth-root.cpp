class Solution {
    // bool chech(int mid, int n, int m){
    //     for(int i=1;i<n;i++){
    //         mid=mid*mid;
    //         if(mid>m) return false;
    //     }
    //     return true;
    // }
  public:
    int nthRoot(int n, int m) {
        int lo=1;
        int hi=m;
        if(m==0 || m==1) return m;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            long long ans=1;
            for(int i=0;i<n;i++){
                ans*=mid;
                
            }
            if(ans==m) return mid;
            else if(ans<m) lo=mid+1;
            else hi=mid-1;
        }
        
        return -1;
        
    }
};
