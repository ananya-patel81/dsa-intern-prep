class Solution {
private:
    int calcost(int num, int k_, int target){
        int curr= num%k_;
        int diff=abs(target-curr);
        return min(diff, k_-diff);
    }
public:
    int minOperations(vector<int>& nums, int k) {
        //vectors of length k for for total cost of even indices and one for odd indices
        //to get each to that modulo
        int n=nums.size();
        vector<int> costeven(k);
        vector<int> costodd(k);
        for(int tar=0;tar<k;tar++){
            int cost=0;
            for(int i=0;i<n;i=i+2){
                cost+=calcost(nums[i],k,tar);
            }
            cout<<cost;
            costeven[tar]=cost;
        }

        for(int tar=0;tar<k;tar++){
            int cost=0;
            for(int i=1;i<n;i=i+2){
                cost+=calcost(nums[i],k,tar);
            }
            cout<<cost;
            costodd[tar]=cost;
        }
        int mincost=INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j) continue;
                else{
                    mincost=min(mincost,costodd[i]+costeven[j]);
                }
            }
        }

        return mincost;
        
        
    }
};
