// for optimal use Moore's voting algo

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int el;
        for(int i=0; i<n; i++){
            if(cnt==0){
                el=nums[i];
                cnt++;
                
            }
            else if( nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int cnt2=0;

        for(int i=0; i<n;i++){
            if(nums[i]==el){
                cnt2++;
            }
        }

        if(cnt2 >n/2) return el;

        return -1;
        
    }
};
