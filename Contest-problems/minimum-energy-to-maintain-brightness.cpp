class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        //we want to find ke k bulbs kitni brightness kar sakte hai; 
        // a bulb at max can illuminate 3 positions, so k can illuminate at most 3k 
        //positions unless 3k>n, so we do maxIll(k)=min(n,3k); And then we find the 
        //least k whose brightness is >= given brightness.
        sort(intervals.begin(),intervals.end());
        int curL= intervals[0][0];
        int curR=intervals[0][1];
        int m=intervals.size();
        long long  dur=0;
        for(int i=1;i<m;i++){
            if(curR>=intervals[i][0]){
                curR=max(curR,intervals[i][1]);
            }
            else{ // the below is in else block so we move onto the next interval only after 
            //we've passed a commmon merged interval;
                dur+=(long long)(curR-curL+1);
                curR=intervals[i][1];
                curL=intervals[i][0];
            }
            
        }

        dur+=(long long)(curR-curL+1);
        
        long long min_bulb=(brightness+2)/3;
        

        long long  ans=min_bulb*dur;
        
        return ans;

        
    }
};
