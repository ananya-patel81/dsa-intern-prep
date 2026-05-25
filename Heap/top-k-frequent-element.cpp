struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // To build a Max-Heap based on frequency (assuming second is frequency)
        return a.second < b.second; 
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // a min heap of size k, with the comparator for the frequency. 
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> maxH;
        unordered_map<int,int> mpp;
        vector<int> result;
        for(int num : nums){
            mpp[num]++;
        }

        
        for(auto entry : mpp){
            maxH.push({entry.first,entry.second});
            
        }

        for(int i=0;i<k;i++){
            result.push_back(maxH.top().first);
            maxH.pop();
            
        }

        return result;



    }
};
