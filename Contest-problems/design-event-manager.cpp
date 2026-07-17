struct compare{
    bool operator()(auto& p1, auto& p2){
        if(p1.second == p2.second) return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

class EventManager {
    
    unordered_map<int,int> mpp; //eventid , priority;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    
public:
    EventManager(vector<vector<int>>& events) {
        
        for(auto& event : events){
            int eventid = event[0];
            int prior = event[1];
            mpp[eventid]=prior;
            pq.push({eventid,prior});
        }
        
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        // int oldprior= mpp[eventId];
        // vector<pair<int,int>> temp;
        // // bool flag = false;
        // while(!pq.empty()){
        //     int el = pq.top().first;
        //     if(el==eventId){
        //         mpp[eventId]=newPriority;
        //         pq.pop();
        //         pq.push({eventId,newPriority});
        //         break;
        //     }
        //     temp.push_back({el,mpp[el]});
        //     pq.pop();
            
        // }
        // for(auto& event : temp){
        //     pq.push(event);
        // }
        
       
        pq.push({eventId,newPriority});
        mpp[eventId]=newPriority;
        
        
    }
    
    int pollHighest() {
        // int maxId = -1;
        // int maxprior=INT_MIN;
        // for(auto& event : mpp){
        //     int id = event.first;
        //     int prior = event.second;
        //     if(maxprior < prior){
        //         maxId = id;
        //         maxprior = prior;
        //     }
        //     else if(maxprior == prior){
        //         if(maxId > id) maxId = id;
        //     }
        // }
        int maxId = -1;
        if(mpp.size()==0) return -1;
        while(!pq.empty()){
            auto event = pq.top();
            if(mpp[event.first]==event.second){
                maxId = event.first;
                mpp.erase(event.first);
                break;
            }
            pq.pop();
        }
        return maxId;
        
        // vector<pair<int,int>> myMap(mpp.begin(),mpp.end());
        // sort(myMap.begin(),myMap.end(),[](auto& a1, auto& a2){
        //     if(a1.second==a2.second){
        //         return a1.first<a2.first;
        //     }
        //     return a1.second > a2.second;
        // });
        // int maxId = myMap[0].first;
        
        

        // mpp.erase(maxId);
        // return maxId;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
