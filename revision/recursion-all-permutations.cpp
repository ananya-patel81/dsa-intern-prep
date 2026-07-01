// LC 46

class Solution {
    void helper( vector<int>& nums, vector<int>& perm, vector<vector<int>>& ans,vector<bool>& visited){
        if(perm.size()==nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++){ //we start from index 0 till the end so we explore all the possibilities available at that time; 
            if(!visited[i]){
                visited[i]=true;
                perm.push_back(nums[i]);
                helper(nums,perm,ans,visited);
                perm.pop_back(); //backtrack
                visited[i]=false;

            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vector<bool> visited(nums.size(),false);
        helper(nums,perm,ans,visited);
        return ans;
        
    }
};
