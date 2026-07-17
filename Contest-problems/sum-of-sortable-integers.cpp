class Solution {
    bool check(vector<int>& nums, int len){
        int n = nums.size();
        int minn = 0;
        for(int i =0;i<n;i+=len){
            if(nums[i]<minn) return false;
            bool point = false;
            int maxx = nums[i];
            for(int j = i+1;j<i+len;j++){
                if(nums[j]<minn) return false;
                maxx= max(maxx,nums[j]);
                if(nums[j]<nums[j-1]){
                    if(point) return false;
                    point = true;
                }
            }
            if(point){
                if(nums[i]<nums[i+len-1]) return false;
            }
            minn = maxx;
        }
        return true;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            if(check(nums,k)) ans+=k;
        }
        return ans;
    }
};
