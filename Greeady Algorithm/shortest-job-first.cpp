class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int dur : bt){
            minH.push(dur);
        }
        int currdur=0;
        int cnt=0;
        int nextadd=0;
        
        while(!minH.empty()){
            int curr=minH.top();
            minH.pop();
            cnt++;
            nextadd+=currdur;
            currdur+=curr;
            
        }
        return nextadd/cnt;
    }
    
};
