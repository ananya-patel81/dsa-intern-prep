class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        for(int i=0; i<n; i++){
            xor1^=nums[i];
        }

        return xor1;

        
    }
};

// remember xor is a reserved word, hence we used xor1. Also xor of 0 with any number is that number itself and xor of two same numbers is 0.
