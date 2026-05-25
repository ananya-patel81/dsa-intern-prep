struct Compare {
    bool operator()(const pair<double,pair<int,int>>& a, const pair<double,pair<int,int>>& b) {
        // To build a Max-Heap based on frequency (assuming second is frequency)
        return a.first < b.first; 
    }
};
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, Compare> maxH;
        int n=val.size();
        for(int i=0;i<n;i++){
            maxH.push({(double)val[i]/wt[i],{val[i],wt[i]}});
        }
        int weight=capacity;
        double ans=0;
        while (!maxH.empty() && weight > 0) {
            auto topItem = maxH.top();
            maxH.pop(); // Pop it immediately to avoid infinite loops
            
            int item_val = topItem.second.first;
            int item_wt = topItem.second.second;
            double ratio = topItem.first;
            
            if (item_wt <= weight) {
                // Take the whole item
                ans += (double)item_val;
                weight -= item_wt; // 3. Update the remaining capacity!
            } 
            else {
                // 4. Take the fraction of what's left based on remaining 'weight'
                ans += ratio * weight;
                weight = 0; // Knapsack is full now
                break;
            }
        }
        
        return ans;
    }
};
