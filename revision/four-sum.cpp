class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                
                int k=n-1;
                int l=j+1;
                while(l<k){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[l];
                    sum+=nums[k];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[k]});
                        k--;
                        l++;
                        while(k>l && nums[l]==nums[l-1]) l++;
                        while(k>l && nums[k]==nums[k+1]) k--;
                    }
                    else if(sum<target) l++;
                    else if(sum>target) k--;
                }
                
            }
        }

        return ans;
    }
};
