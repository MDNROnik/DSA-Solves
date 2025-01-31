vector<pair<int, int>> post;
map<int, set<int>>follow_List;
int now_box=-1;
class Twitter {
public:
    Twitter() {
        post.clear();
        follow_List.clear();
        now_box=-1;
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId, tweetId});now_box++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        set<int>s=follow_List[userId];
        int n=10;
        if(now_box==-1){
            return ans;
        }
        for(int i=now_box;i>=0;i--){
            if(n==0){
                break;
            } 
            if(post[i].first==userId || s.contains(post[i].first)){
                ans.push_back(post[i].second);n--;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follow_List[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_List[followerId].erase(followeeId);
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