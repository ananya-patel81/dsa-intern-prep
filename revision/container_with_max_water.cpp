class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int max_water=0;
        
        while(l<r){
            //water = min(nums[l],nums[r])-nums[i];
            int width=r-l;
            int height=min(nums[l],nums[r]);
            int curr_area=width*height;
            max_water=max(max_water,curr_area);
            if(nums[l]<nums[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return max_water;
        
    }
};
