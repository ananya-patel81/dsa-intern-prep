class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            vector<int> freq(n+1,0);
            int mx=0;
            int s=0;
            
            for(int j=i;j<n;j++){
                if(mpp[nums[j]]){
                    freq[mpp[nums[j]]]--;
                }
                mpp[nums[j]]++;
                freq[mpp[nums[j]]]++;
                if(mx<mpp[nums[j]]){
                    mx=mpp[nums[j]];
                    s=1;
                }
                else if(mx==mpp[nums[j]]){
                    s++;
                }
                int distinct=mpp.size();
                if(distinct==1){
                    ans=max(ans,(j-i+1));
                }
                else if((mx%2==0)&& s<distinct && freq[mx/2]==distinct-s){
                    ans=max(ans,(j-i+1));
                }
            }
        }
        return ans;
    }
};
