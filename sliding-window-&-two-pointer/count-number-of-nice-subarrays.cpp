class Solution {
private: 
    int atMostKodd(vector<int>& nums, int k){
        int cnt=0;
        int num_of_odd=0;
        int left=0;
        int right=0;
        int n=nums.size();
        while(right<n){
            if (nums[right]%2==1) num_of_odd++;
            while(num_of_odd>k){
                if(nums[left]%2==1) num_of_odd--;
                left++;
            }
            cnt+=(right-left+1);
            right++;

        }
        return cnt; 
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKodd(nums,k) - atMostKodd(nums,k-1);
        
        
    }
};
