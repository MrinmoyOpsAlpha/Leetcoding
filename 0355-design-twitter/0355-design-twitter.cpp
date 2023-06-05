class Twitter {
private:
    vector<pair<int, int>> posts;  //user, tweet
    unordered_map<int, unordered_set<int>> followMap; // user, id they follow
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 10;
        vector<int> results;
        
        for(int i=posts.size() - 1 ;i>=0;i--){
            if(count == 0) break;
            
            int followingID = posts[i].first;
            int tweetID = posts[i].second;
            unordered_set<int> following = followMap[userId];
            
            if (following.find(followingID) != following.end() || followingID == userId) {
                results.push_back(tweetID);
                count--;
            }
        }
        
        return results;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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