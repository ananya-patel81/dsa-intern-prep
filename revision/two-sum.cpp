class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mpp; //number and its index in the array;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mpp.find(rem)!=mpp.end()){
                return {i,mpp[rem]};
            }
            mpp[nums[i]]=i;
        }

        return {-1,-1};
        
    }
};
