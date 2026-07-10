class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int val=nums[i];
            if(lis.back()<val){
                lis.push_back(val);
            }
            else{
                auto it = lower_bound(lis.begin(),lis.end(),val)-lis.begin();
                lis[it]=val;
            }


        }

        return lis.size();
    }
};
