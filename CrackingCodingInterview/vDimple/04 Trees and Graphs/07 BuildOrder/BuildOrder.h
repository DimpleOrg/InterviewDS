#pragma once
#include<iostream>
#include<unordered_set>
#include<stack>
#include<unordered_map>
#include<list>

template<typename T>
class BuildOrder
{
private:
	std::unordered_set<T> isVisited;
	std::unordered_map<T, std::vector<T>> m;
	std::stack<T> res;

public:
	
	std::stack<T> getBuildOrder(std::vector<T> proj, std::list<std::pair<T, T>> pairOfProjects)
	{
		for (auto each : pairOfProjects)
		{
			m[each.first].push_back(each.second);
		}

		for (auto each : proj)
		{
			if (isVisited.find(each) == isVisited.end())
				topologicalSort(each);
		}
		return res;
	}

	void topologicalSort(T src)
	{
		isVisited.insert(src);
		for (int i=0;i< m[src].size();i++)
		{
			if (isVisited.find(m[src][i]) == isVisited.end())
				topologicalSort(m[src][i]);
		}

		res.push(src);
	}
};