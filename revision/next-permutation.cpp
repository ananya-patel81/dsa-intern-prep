class Solution {
private:
    void swapind(int i, int j, vector<int>& nums){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[n-1];
        int i=n-1;
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int j=n-1;
            while(nums[i-1]>=nums[j]){ //to swap with the just next greater element.
                j--;
            }
            swapind(i-1,j,nums);
            reverse(nums.begin()+(i),nums.end());
        }
        
        
    }
};
