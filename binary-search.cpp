//Iterative method

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return -1;
        
    }
};

//Recursive method
class Solution {
private:
    int binarysearch(vector<int>& nums, int low, int high, int target){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target){
            return binarysearch(nums,low,mid-1,target);

        }
        return binarysearch(nums,mid+1,high,target);
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        return binarysearch(nums,low,high,target);
        
    }
};
