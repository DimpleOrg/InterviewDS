#pragma once
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>

class Twitter {
	int userId;
	int tweetId;
	int followerId;
	int followeeId;

	std::map<int, std::set<int>> following;
	std::map<int, std::vector<std::pair<int, int>>> post;
	int postIndex;

public:
	/** Initialize your data structure here. */
	Twitter() {
		userId = 0;
		tweetId = 0;
		followerId = 0;
		followeeId = 0;
		postIndex = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		post[userId].push_back({ postIndex++, tweetId });
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	std::vector<int> getNewsFeed(int userId) {
		std::vector<int> followeelist;
		std::vector<int> res;
		for (auto x : following[userId])
			followeelist.push_back(x);
		followeelist.push_back(userId);

		std::priority_queue<std::pair<int, int>> pq;
		for (int i = 1; i <= 10; i++)
		{
			for (auto x : followeelist)
			{
				int count = post[x].size() - i;
				if (count >= 0)
					pq.push(post[x][count]);			//didn't get this
			}

			if (pq.empty())
				break;

			auto val = pq.top();
			res.push_back(val.second);
			pq.pop();
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
			following[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		following[followerId].erase(followeeId);
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