class Solution {

private:
    bool validSum(long long sum,int x){
        
        if(sum%10!=x) return false;
        int rem=0;
        while(sum>0){
            rem=sum%10;
            sum=sum/10;
        }
        if(rem!=x) return false;
        return true;
    }
    
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        //take not take can be applied, and when not taking make the 
        //sum 0; and when taking, add the num to the sum;
        //base case is when i==n, return count;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(validSum(sum,x)) ans++;
            }
        }

        return ans;
        
        
    }
};
