class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=0;
        long long max_sum= LONG_MIN;
        int n=nums.size();
        int start; // in case we have to return the subarray too.
        int end
        for(int i=0; i<n; i++){
            if(sum<0){
                start=i
                sum=nums[i];
                max_sum=max(sum,max_sum);
            }
            
            else{
                sum+=nums[i];
                max_sum=max(sum,max_sum);
            }
            if(max_sum<=sum){
                max_sum=sum;
                end=i;
            
        }

        //the max sum subarray is from index start to end. 

        return max_sum;
        
    }
};
