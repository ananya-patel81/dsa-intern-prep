class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //we use bitmasking for this 
        vector<vector<int>> ans;
        int n=nums.size();
        int subsets=(1<<n);
        for(int i=0;i<subsets;i++){
            vector<int> subset;
            for(int idx=0;idx<n;idx++){
                if(i&(1<<idx)){
                    subset.push_back(nums[idx]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};
