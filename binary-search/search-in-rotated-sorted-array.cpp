class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ind=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ind=mid;
                break;

            } 
            else if(nums[low]<=nums[mid]){ // matlab sorted hai
                if(target>=nums[low] && target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }

            }
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low=mid+1;

                }
                else{
                    high=mid-1;
                }
                
            }
        }

        return ind;
        
    }
};
