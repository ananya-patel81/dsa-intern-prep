// Brute mein toh bas ek temp banake usme saare non zeroes daaldo, phir start se array mein woh daaldo and fill the rest with zeros. TC=O(2n)
// SC= O(n)
// below is optimal one, jiska TC= O(n) and SC=O(1)



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        for(int i=0, j=0; i<n; i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        

        
    }
};
