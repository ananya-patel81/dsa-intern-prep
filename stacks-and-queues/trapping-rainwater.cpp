class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int leftmax=height[l];
        int rightmax=height[r];
        int total=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(leftmax>height[l]){
                    total+=leftmax-height[l];
                }
                else leftmax = height[l];
                l++;
            }
            else{
                if(rightmax>height[r]){
                    total+=rightmax-height[r];
                }
                else{
                    rightmax=height[r];
                }
                r--;
            }
        }
        return total;
    }
};
