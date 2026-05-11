// Solution article link for better understanding: https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        long long pref=1;
        long long suff=1;
        long long maxi=LLONG_MIN;
        for(int i=0;i<n;i++){
            if(pref==0) pref=1; // handling zeroes;
            if(suff==0) suff=1;


            pref= pref*nums[i];
            suff=suff*nums[n-i-1];
            
            long long temp=max(pref,suff);
            maxi=max(maxi,temp);


        }
        return maxi;
        
    }
};
