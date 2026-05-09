class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=0;
        long long max_sum= LONG_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(sum<0){
                sum=nums[i];
                max_sum=max(sum,max_sum);
            }
            else{
                sum+=nums[i];
                max_sum=max(sum,max_sum);
            }
        }

        return max_sum;
        
    }
};
