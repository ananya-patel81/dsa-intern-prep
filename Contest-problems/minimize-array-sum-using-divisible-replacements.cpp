class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<bool> present(mx+1,false);
        vector<int> best(mx+1,INT_MAX);

        for(int num : nums){
            present[num]=true;
        }

        for(int v=1;v<=mx;v++){
            if(!present[v]) continue;
            for(int m=v; m<=mx;m=m+v){
                best[m]=min(best[m],v);
            }
        }

        long long sum=0;
        for(int num : nums){
            sum+=best[num];
        }

        return sum;
        
    }
};
