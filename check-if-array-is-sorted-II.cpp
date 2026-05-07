class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int countlessthan=0;
        for(int i=0; i<n-1;i++){
            if(nums[i]>nums[i+1]) countlessthan++;
        }

        if(countlessthan==0){
            return true;

        

        } 
        if(countlessthan==1 && nums[0]>=nums[n-1]){
            return true;
        }
        return false;
    }
};
