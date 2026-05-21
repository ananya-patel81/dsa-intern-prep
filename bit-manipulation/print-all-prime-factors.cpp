class Solution {
  public:
    vector<int> primeFactors(int n) {
        // code here
        vector<int> ans;
        for(int i=2; i*i<=n;i++){
            while(n%i==0){
                ans.push_back(i);
                n=n/i;
            }
        }
        if(n!=1) ans.push_back(n);
        return ans;
    }
};
