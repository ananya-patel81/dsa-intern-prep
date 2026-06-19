class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el=nums[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int cnt2=0;

        for(int num : nums){
            if(num==el){
                cnt2++;
            }
        }

        if(cnt2<(n/2)) return -1;
        return el;
        
    }
};
