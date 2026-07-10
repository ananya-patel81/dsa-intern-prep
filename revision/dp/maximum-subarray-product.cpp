//prefix-suffix-product, and when product is 0 of either prefix or suffix, set them to 1, and take tmep as max of prefix and suffix product so far and amxi as max of maxi and temp;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        long long prefix=1;
        long long suffix = 1;
        long long maxi=LLONG_MIN;
        for(int i = 0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-1-i];
            
            long long temp=max(prefix,suffix);
            maxi=max(maxi,temp);

        }

        return maxi;
    }
};
