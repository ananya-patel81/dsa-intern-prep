class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            sum+= max(0,nums[i]-nums[i+1]);
        }
        return sum;
    }
};
