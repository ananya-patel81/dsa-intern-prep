class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        if(n==1 && s=="1") return nums[0];
        if(n==1 && s!="1") return 0;
        long long ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                i++;
                continue;
            }
            int L=i;
            while(i<n && s[i]=='1'){
                i++; // so i is oncremented for next iteration
            }
            int R=i-1;

            int st= (L==0) ? 0 : L-1;  
            long long sum=0;
            int mini=INT_MAX;
            for(int k=st;k<=R;k++){
                sum+=nums[k];
                mini=min(mini,nums[k]);
            }

            if(L==0) ans+=sum;  // kyuki agar L pehla element hai and usse block start ho raha 1's ka
            // toh tum kuch skip nahi kar sakte as there is no place at the back or in between to go to.
            if(L!=0) ans+= (sum-(long long)mini);

        }
        

        return ans;

        
    }
};
