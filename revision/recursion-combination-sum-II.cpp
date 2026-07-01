class Solution {
private:
    void helper(int ind, vector<vector<int>>& ans, vector<int>& ds, int target, vector<int>& candidates){
        
        if(target==0){ //NOTICE IT DID NOT NEED "IF IND==CANDIDATES>SIZE(); 
            ans.push_back(ds);
            return;
        }
            
        

        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target) break; // we can do this since our candidates are sorted;
            if(i>ind && candidates[i]==candidates[i-1]) continue; //IMPORTANT, TO REMOVE DUPLICATE COMBINATIONS 
           
            ds.push_back(candidates[i]);
            helper(i+1,ans,ds,target-candidates[i],candidates); //you can only take an element once, hence after taking the element, you go onto 
          //the next element; 
            ds.pop_back();
            
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds; 
        vector<vector<int>> ans;
        helper(0,ans,ds,target,candidates);
        return ans;
        
    }
};
