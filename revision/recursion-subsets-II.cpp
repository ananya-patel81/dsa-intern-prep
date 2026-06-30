class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums, int n,int index){
        ans.push_back(ds);
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1]) continue; //cruciall to understand, ke this is to not have duplicate subsets, but 
          //does have the elements that might be repeated in the array if they are a part of the subset;
            ds.push_back(nums[i]);
            helper(ans,ds,nums,n,i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end()); //important to club all the duplicate elements together;
        vector<vector<int>> ans;
        vector<int> ds;
        helper(ans,ds,nums,n,0);
        return ans;
        
    }
};
