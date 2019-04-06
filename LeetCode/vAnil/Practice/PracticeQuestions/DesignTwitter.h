#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Twitter {
	map<int, set<int>> fMap;
	map<int, vector<pair<int, int>>> tMap;
	int tIndex = 0;
public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tMap[userId].push_back({ tIndex++, tweetId });
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	std::vector<int> getNewsFeed(int userId) {
		vector<int> followeeList;
		vector<int> result;
		for (auto x : fMap[userId])
		{
			followeeList.push_back(x);
		}
		followeeList.push_back(userId);

		priority_queue<pair<int, int>> pq;

		for (int i = 1; i <= 10; i++)
		{
			for (auto x : followeeList)
			{
				int c = tMap[x].size() - i;
				if (c >= 0)
					pq.push(tMap[x][c]);
			}

			if (pq.empty())
				break;

			auto val = pq.top();

			result.push_back(val.second);
			pq.pop();
		}

		return result;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId)
			fMap[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		fMap[followerId].erase(followeeId);
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
