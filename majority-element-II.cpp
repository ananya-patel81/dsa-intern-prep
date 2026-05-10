class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n=nums.size();
        int mini= n/3;
        int el1= INT_MIN;
        int el2 = INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0; i<n; i++){
            if(cnt1==0 && el2 != nums[i]){
                el1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && el1 != nums[i]){
                el2=nums[i];
                cnt2++;
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }

        }
        vector<int> ls;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
        }
        if(cnt1> mini) ls.push_back(el1);
        if(cnt2> mini) ls.push_back(el2);
        return ls;
    }
};
