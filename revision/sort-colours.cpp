class Solution {
private:
    void swap(int i, int j, vector<int>& nums){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(low,mid,nums);
                low++;
                mid++;

            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(high,mid,nums);
                high--;
                //no mid++ because you swapped with high, and high too had an unsorted element, so you don't know what it is and whether does it contribute to being sorted or not. Whereas when swapping with low, you know you are bringing a 1 and you also know that mid-1 index whould have a 1, so you increment, do pen and paper practice to understand. 

            }

        }

        
    }
};
