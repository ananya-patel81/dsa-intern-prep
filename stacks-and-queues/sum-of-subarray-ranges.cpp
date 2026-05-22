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

    vector<int> nge(vector<int>& arr, int n){ // this stores the index of the nse;
        vector<int> nse(n,n);
        stack<int> mini;
        for(int i=n-1;i>=0;i--){
            while(!mini.empty() && arr[mini.top()]<=arr[i]){
                mini.pop();
            }
            
            if(!mini.empty()){
                nse[i]=mini.top();
            }
            mini.push(i);
        }
        return nse;
    }

    vector<int> pgee(vector<int>& arr, int n){
        vector<int> psee(n,-1);
        stack<int> mini;
        for(int i=0;i<=n-1;i++){
            while(!mini.empty() && arr[mini.top()]<arr[i]){
                mini.pop();
            }
        
            if(!mini.empty()){
                psee[i]=mini.top();
            }
            mini.push(i);
        }
        return psee;

    }

    long long  sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nseArr= nse(arr,n);
        vector<int> pseeArr=psee(arr,n);
        long long total=0;
        

        for(int i=0; i<n; i++){
            long long left=i-pseeArr[i];
            long long right=nseArr[i]-i;

            long long contribution=(left*right);
            contribution=(contribution*arr[i]);

            total= (total + contribution);
        }

        return total;



        
    }

    long long  sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int> ngeArr= nge(arr,n);
        vector<int> pgeeArr=pgee(arr,n);
        long long total=0;
        

        for(int i=0; i<n; i++){
            long long left=i-pgeeArr[i];
            long long right=ngeArr[i]-i;

            long long contribution=(left*right);
            contribution=(contribution*arr[i]);

            total= (total + contribution);
        }

        return total;



        
    }


public:
    long long subArrayRanges(vector<int>& nums) {

        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        
    }
};
