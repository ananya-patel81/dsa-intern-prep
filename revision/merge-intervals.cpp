class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newInt;
        newInt.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>newInt.back()[1]){
                newInt.push_back(intervals[i]);
            }
            else{
                newInt.back()[1]=max(newInt.back()[1],intervals[i][1]);
            }
        }

        return newInt;
        
    }
};
