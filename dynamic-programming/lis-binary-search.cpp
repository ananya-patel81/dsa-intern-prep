class Solution {
// private:
//     int f(int ind,int prevInd,vector<int>& nums,vector<vector<int>>& dp,int n){
//         if(ind==n) return 0;
//         if(dp[ind][prevInd]!=-1) return dp[ind][prevInd];
//         int len=0+f(ind+1,prevInd,nums,dp,n);
        
//         if(prevInd==0 || nums[ind]>nums[prevInd-1]){
//             len=max(len,1+f(ind+1,ind+1,nums,dp,n));
//         }
//         return dp[ind][prevInd]=len;

//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin(); //to find the element just greater than nums[i] and replace it. 
                //lower_bound returns an iterator pointing to the first element in a partitioned or sorted range that is greater than or equal to (≥) the given value.
                temp[ind]=nums[i];
            }
        }

        return temp.size();
        //REMEMBER TEMP IS NOT THE LIS AND THIS METHOD IS TO JUST RETURN THE LENGTH;
    }
};
