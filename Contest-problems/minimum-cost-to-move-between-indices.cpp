class Solution {
    vector<int> findClosest(vector<int> nums){
        int n=nums.size();
        vector<int> closest(n,-1);
        closest[0]=1;
        closest[n-1]=n-2;
        for(int i=1;i<n-1;i++){
            int diff1 = abs(nums[i]-nums[i-1]);
            int diff2 = abs(nums[i]-nums[i+1]);
            if(diff1>diff2){
                closest[i]=i+1;
            }
            else closest[i]=i-1;
        }
        return closest;
        
    }
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> distLtoR(n,0);
        vector<int> distRtoL(n,0);
        vector<int> closest = findClosest(nums);
        for(int i=1;i<n;i++){
            if(i==closest[i-1]) distLtoR[i]=distLtoR[i-1]+1;
            else distLtoR[i] = distLtoR[i-1]+ abs(nums[i]-nums[i-1]);
            
        }
        for(int i=n-2;i>=0;i--){
            if(i==closest[i+1]) distRtoL[i]=distRtoL[i+1]+1;
            else distRtoL[i]=distRtoL[i+1]+abs(nums[i]-nums[i+1]);
        }
        vector<int> ans(m);
        for(int q=0;q<m;q++){
            int from = queries[q][0];
            int to = queries[q][1];
            if(from<=to) ans[q]=distLtoR[to]-distLtoR[from];
            else ans[q]=distRtoL[to]-distRtoL[from];
        }
        
        return ans;
        
    }
};
