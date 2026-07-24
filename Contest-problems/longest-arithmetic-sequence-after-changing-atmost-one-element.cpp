class Solution {
public:
    int longestArithmetic(vector<int>& nums) { 
        int n = nums.size();
        vector<int> left(n,1) , right(n,1);
        left[1]=2;
        right[n-2]=2;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                left[i]=left[i-1]+1;
            }
            else left[i]=2;
        }
        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                right[i]=right[i+1]+1;
            }
            else right[i]=2;
        }

        int max_len=INT_MIN;
        for(int i=0;i<n;i++){
            if(i>0) max_len = max(max_len,left[i-1]+1);
            if(i<n-1) max_len = max(max_len,right[i+1]+1);
        }

        for(int i=1;i<n-1;i++){
            int diff_two = (nums[i+1]-nums[i-1]);
            if(diff_two%2) continue;
            int d = diff_two/2;

            int l_len = 1;
            if(i>=2 && nums[i-1]-nums[i-2]==d){
                l_len = left[i-1];
            }
            int r_len = 1;
            if(i<=n-3 && nums[i+2]-nums[i+1]==d){
                r_len = right[i+1];
            }

            max_len = max(max_len,l_len+1+r_len);
        }
        return max_len;
    }
};
