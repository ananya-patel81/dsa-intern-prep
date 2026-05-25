class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<tuple<int,int,int>> pq;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        vector<int> result;
        
        set<pair<int,int>> visited;
        
        pq.push({a[0]+b[0],0,0});
        visited.insert({0,0});
        
        while(k-- && !pq.empty()){
            auto [sum,i,j] = pq.top();
            pq.pop();
            
            result.push_back(sum);
            if(i+1<a.size() && !visited.count({i+1,j})){
                pq.push({a[i+1]+b[j],i+1,j});
                visited.insert({i+1,j});
            }
            if(j+1<b.size() && !visited.count({i,j+1})){
                pq.push({a[i]+b[j+1],i,j+1});
                visited.insert({i,j+1});
            }
            
            
        }
        
        return result;
        
        
    }
};
