class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        followMap[userId].insert(userId);
        for(int followeeId: followMap[userId]) {
            if(tweetMap.contains(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size()-1;
                maxHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while(!maxHeap.empty() && res.size() < 10) {
            vector<int> curr = maxHeap.top();
            maxHeap.pop();
            int index = curr[3];
            res.push_back(curr[1]);
            if(index > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][index-1];
                maxHeap.push({tweet[0], tweet[1], curr[2], index-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
