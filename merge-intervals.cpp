//You basically first sort the intervals, then with each interval, you compare it s ending point with the next one's starting point. 
//if the next starting point is less than or equal to the previous one's ending point, merge them. 
// to merge them, answer array ke last element [ans.back()] ke ending point ko max(ans.back()[1],intervals[i][1]) karna hoga.
// warna if the condition is not true just add the next interval in the answer list. 

//TC = O(NlogN) + O(N);
//SC= just for returning the answer O(N);



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }

        return ans;
        
    }
};
