class Twitter {
private:
    // 1. Move the variables here so the entire class can see them
    unordered_map<int, vector<pair<int, int>>> user_posts;
    unordered_map<int, unordered_set<int>> user_followers;
    int time;
public:
    Twitter() {
        time=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_posts[userId].push_back({time,tweetId});
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        for(auto &t : user_posts[userId]){
            pq.push(t);
            while(pq.size()>10){
                pq.pop();

            }
        }
        for(int followee : user_followers[userId]){
            for(auto &t : user_posts[followee]){
                pq.push(t);
                while(pq.size()>10){
                    pq.pop();
                }

            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(),result.end());
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        user_followers[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        user_followers[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
