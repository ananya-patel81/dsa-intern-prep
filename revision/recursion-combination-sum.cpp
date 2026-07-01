class Solution {
private:
    void helper(int i, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates, int target){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(target>=candidates[i]){
            ds.push_back(candidates[i]);
            helper(i,ds,ans,candidates,target-candidates[i]);
            ds.pop_back();
        }
        helper(i+1,ds,ans,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        helper(0,ds,ans,candidates,target);
        return ans;
        
    }
};
