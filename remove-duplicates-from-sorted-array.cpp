class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr= nums[0];
        vector<int> ans;
        ans.push_back(curr);
        int k=1;
        for(int i=0; i<n;i++){
            if(nums[i]!=curr){
                curr=nums[i];
                ans.push_back(curr);
                k++;
            }
            else continue;
        }

        for(int i=0; i<k; i++){
            nums[i]=ans[i];
        }

        return k;
    }
};
