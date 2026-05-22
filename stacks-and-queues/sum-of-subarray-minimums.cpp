class Solution {
private:
    vector<int> nse(vector<int>& arr, int n){ // this stores the index of the nse;
        vector<int> nse(n,n);
        stack<int> mini;
        for(int i=n-1;i>=0;i--){
            while(!mini.empty() && arr[mini.top()]>=arr[i]){
                mini.pop();
            }
            
            if(!mini.empty()){
                nse[i]=mini.top();
            }
            mini.push(i);
        }
        return nse;
    }

    vector<int> psee(vector<int>& arr, int n){
        vector<int> psee(n,-1);
        stack<int> mini;
        for(int i=0;i<=n-1;i++){
            while(!mini.empty() && arr[mini.top()]>arr[i]){
                mini.pop();
            }
        
            if(!mini.empty()){
                psee[i]=mini.top();
            }
            mini.push(i);
        }
        return psee;

    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nseArr= nse(arr,n);
        vector<int> pseeArr=psee(arr,n);
        long long total=0;
        int mod=1e9+7;

        for(int i=0; i<n; i++){
            long long left=i-pseeArr[i];
            long long right=nseArr[i]-i;

            long long contribution=(left*right)%mod;
            contribution=(contribution*arr[i])%mod;

            total= (total + contribution)%mod;
        }

        return (int)total;



        
    }
};
