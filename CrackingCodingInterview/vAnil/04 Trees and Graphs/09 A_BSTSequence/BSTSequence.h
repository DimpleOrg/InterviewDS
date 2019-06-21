#pragma once
#include <iostream>
#include <list>
#include <vector>

template <typename T>
class BST_NODE_09
{
public:
	T data;
	BST_NODE_09<T> *left = nullptr;
	BST_NODE_09<T> *right = nullptr;

	BST_NODE_09(T input) : data(input) {}
};

template <typename T>
class BST_09
{
public:

	void insert(T data) {
		if (!root)
		{
			root = new BST_NODE_09<T>(data);
		}
		else
		{
			auto iter = root;
			auto prev = iter;
			while (iter)
			{
				prev = iter;
				if (data < iter->data)
				{
					iter = iter->left;
				}
				else if (data > iter->data)
				{
					iter = iter->right;
				}
				else
				{
					return;
				}
			}

			if (data < prev->data)
				prev->left = new BST_NODE_09<T>(data);
			else if (data > prev->data)
				prev->right = new BST_NODE_09<T>(data);
		}
	}

	void insert(std::list<T> dList)
	{
		for (auto val : dList)
		{
			insert(val);
		}
	}

	std::list<std::list<T>> getBSTSequences()
	{
		return getBSTSequences(root);
	}


private:
	BST_NODE_09<T> *root = nullptr;

	void mergeSeq(std::list<std::list<T>>& result, std::list<T> x, std::list<T> y, std::list<T> prefixList)
	{
		if (x.size() == 0 || y.size() == 0)
		{
			prefixList.splice(prefixList.end(), x);
			prefixList.splice(prefixList.end(), y);

			result.push_back(prefixList);
		}
		else
		{
			if (x.size() > 0)
			{
				T front = x.front();
				x.pop_front();
				prefixList.push_back(front);
				mergeSeq(result, x, y, prefixList);
				x.push_front(front);
				prefixList.pop_back();
			}

			if (y.size() > 0)
			{
				T front = y.front();
				y.pop_front();
				prefixList.push_back(front);
				mergeSeq(result, x, y, prefixList);
				y.push_front(front);
				prefixList.pop_back();
			}
		}
	}

	std::list<std::list<T>> mergeSeqList(std::list<std::list<T>> l1, std::list<std::list<T>> l2, T prefix)
	{
		std::list<std::list<T>> lists;
		for (auto x : l1)
		{
			for (auto y : l2)
			{
				std::list<std::list<T>> result;
				mergeSeq(result, x, y, { prefix });
				lists.splice(lists.begin(), result);
			}
		}

		return std::move(lists);
	}


	std::list<std::list<T>> getBSTSequences(BST_NODE_09<T> *node)
	{
		std::list<std::list<T>> lists;
		if (!node)
		{
			lists.push_back({});
			return lists;
		}
		else
		{
			T curdata = node->data;

			auto l = getBSTSequences(node->left);
			auto r = getBSTSequences(node->right);

			auto m = mergeSeqList(l, r, curdata);

			lists.splice(lists.end(), m);
		}

		return std::move(lists);
	}
};
