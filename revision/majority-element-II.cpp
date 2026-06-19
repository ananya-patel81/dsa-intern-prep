class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=0;
        int el2=0;//you can't initialize one since you don't know the array and can't say whether the chosen indexes have the same or different values.
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=el1){
                el2=nums[i];
                cnt2=1;
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int cnt1n=0;
        int cnt2n=0;

        for(int num : nums){
            if(cnt1>0 && num==el1) cnt1n++;
            else if(cnt2>0 && num==el2) cnt2n++;
        }

        if(cnt1>0 && cnt2>0 && cnt1n>(n/3)&& cnt2n>(n/3)) return {el1,el2};
        else if(cnt1>0 && cnt1n>(n/3)) return {el1};
        else if(cnt2>0 && cnt2n>(n/3)) return {el2};
        return {};
        
    }
};
