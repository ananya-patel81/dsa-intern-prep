class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q; //steps, product;
        vector<int> dist(1000,1e9);
        int mod=1000;
        q.push({0,start});
        while(!q.empty()){
            int steps=q.front().first;
            int prod=q.front().second;
            if(prod==end) return steps;
            q.pop();
            for(int i : arr){
                int newprod=(prod*i)%mod;
                if(steps+1<dist[newprod]){
                    dist[newprod]=steps+1;
                    q.push({steps+1,newprod});
                }
            }
        }
        
        return -1;
        
    }
};
