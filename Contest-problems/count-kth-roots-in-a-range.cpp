#include <cmath> 
class Solution {
    bool pown(int mid, int k,int n){
        long long res=1;
        for(int x=1;x<=k;x++){
            res*=mid;
            if(res>n) return false;
        }
        return true;
    }
    int kthrootsTilli(int i, int k){
        int low=0;
        int high=i; 
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(pown(mid,k,i)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
public:
    int countKthRoots(int l, int r, int k) {
        //some way of finding perfect kth powers till a certain i;
        //then f(r)-f(l-1);
        //kth roots till int i is the integral value of i^(1/k);
        
        if(l==0) return kthrootsTilli(r,k)+1;
       
        
        
        return kthrootsTilli(r,k)-kthrootsTilli(l-1,k);
       
    }
};
