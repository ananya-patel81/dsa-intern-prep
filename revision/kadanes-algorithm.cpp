class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=nums[0];
        long long max_sum=sum;
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum<0){
                sum=nums[i];
                max_sum=max(max_sum,sum);

            }
            else{
                sum+=(long long)nums[i];
                max_sum=max(max_sum,sum);
            }
        }

        return (int) max_sum;
        
    }
};
