class Solution {
private:
    int findbound(vector<int>& nums, int target, bool isFirst){
        int n= nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                if(isFirst) high=mid-1;
                else low=mid+1;
                
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findbound(nums,target,true),findbound(nums,target,false)};
        
        
    }
};
