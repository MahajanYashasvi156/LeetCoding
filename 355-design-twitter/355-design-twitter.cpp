class Twitter 
{
    unordered_map<int,unordered_map<int,int>> IFollowed;
    
    vector<pair<int,int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> feed;
        int count = 0;
        for(int i = posts.size()-1;i>=0 and count<10;i--)
        {
            if(posts[i].first==userId || IFollowed[userId][posts[i].first])
            {
                feed.push_back(posts[i].second);
                count++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) 
    {
        IFollowed[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId)
    {
        IFollowed[followerId][followeeId] = 0;   
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