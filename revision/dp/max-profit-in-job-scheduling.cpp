class Solution { //TC = O(NlogN) SC = O(N) almost 
 
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for(int i=0;i<n;i++){
            jobs[i]= {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        map<int,int> dp;
        dp[0]=0;
        for(auto& job : jobs){
            int curr = prev(dp.upper_bound(job[1]))->second + job[2];
            if(curr> dp.rbegin()->second){
                dp[job[0]]=curr;
            }
        }

        return dp.rbegin()->second;
        
    }
};
