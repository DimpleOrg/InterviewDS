#pragma once
#ifndef __BSTSEQUENCE_H_
#define __BSTSEQUENCE_H_

#include<iostream>
#include<list>

template<typename T>
struct binSTnode
{
	T data;
	std::shared_ptr<binSTnode<T>> left;
	std::shared_ptr<binSTnode<T>> right;

	binSTnode(T val) : data(val) { }
};

template<typename T>
class BinSTree
{
	std::shared_ptr<binSTnode<T>> root;
	void insertNodeHelper(std::shared_ptr<binSTnode<T>> root, T val);
	std::list<std::list<T>>  mergeSeqList(std::list<std::list<T>> l1, std::list<std::list<T>> l2, T prefix);
	void mergeSeq(std::list<std::list<T>>& res, std::list<T> x, std::list<T> y, std::list<T> prefix);
	std::shared_ptr<binSTnode<T>> getNode(std::shared_ptr<binSTnode<T>> root, T src, std::shared_ptr<binSTnode<T>>& res);

public:
	void insertNode(T val);
	std::list<std::list<T>> getBSTSequences(std::shared_ptr<binSTnode<T>> root);
	std::shared_ptr<binSTnode<T>> getNode(T src);
};

template<typename T>
inline void BinSTree<T>::insertNode(T val)
{
	if (!root)
		root = std::make_shared<binSTnode<T>>(val);
	else
		insertNodeHelper(root, val);
}

template<typename T>
inline void BinSTree<T>::insertNodeHelper(std::shared_ptr<binSTnode<T>> root, T val)
{
	if (root->data == val)
		throw("duplicate value");

	if (val < root->data)
	{
		if (root->left == nullptr)
		{
			root->left = std::make_shared<binSTnode<T>>(val);
		}
		else
			insertNodeHelper(root->left, val);
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = std::make_shared<binSTnode<T>>(val);
		}
		else
			insertNodeHelper(root->right, val);
	}
}

template<typename T>
inline void BinSTree<T>::mergeSeq(std::list<std::list<T>>& res, std::list<T> x, std::list<T> y, std::list<T> prefix)
{
	if (x.size() == 0 || y.size()==0)
	{
		prefix.splice(prefix.end(), x);
		prefix.splice(prefix.end(), y);
		
		res.push_back(prefix);
	}
	else
	{
		if (x.size() > 0)
		{
			auto item = x.front();
			x.pop_front();
			prefix.push_back(item);
			mergeSeq(res, x, y, prefix);
			prefix.pop_back();
			x.push_front(item);
		}

		if (y.size() > 0)
		{
			auto item = y.front();
			y.pop_front();
			prefix.push_back(item);
			mergeSeq(res, x, y, prefix);
			prefix.pop_back();
			y.push_front(item);
		}
	}
}



template<typename T>
inline std::list<std::list<T>> BinSTree<T>::mergeSeqList(std::list<std::list<T>> l1, std::list<std::list<T>> l2, T prefix)
{
	std::list<std::list<T>> lists;
	for (auto x : l1)
	{
		for (auto y : l2)
		{
			std::list<std::list<T>> res;
			mergeSeq(res, x, y, { prefix });
			lists.splice(lists.begin(), res);
		}
	}
	return lists;
}

template<typename T>
inline std::list<std::list<T>> BinSTree<T>::getBSTSequences(std::shared_ptr<binSTnode<T>> root)
{
	std::list<std::list<T>> resList;

	if (!root)
	{
		resList.push_back({});
		return resList;
	}
	else
	{
		T currData = root->data;

		auto leftSeq = getBSTSequences(root->left);
		auto rightSeq = getBSTSequences(root->right);

		auto mergedSeq = mergeSeqList(leftSeq, rightSeq, currData);

		resList.splice(resList.end(), mergedSeq);
	}

	return resList;
}

template<typename T>
inline std::shared_ptr<binSTnode<T>> BinSTree<T>::getNode(std::shared_ptr<binSTnode<T>> root, T src, std::shared_ptr<binSTnode<T>>& res)
{
	if (!root) return nullptr;

	auto val1 = getNode(root->left, src, res);
	if (val1) return val1;

	if (root->data == src)
		res = root;

	auto val2 = getNode(root->right, src, res);
	if (val2) return val2;

	return res;
}

template<typename T>
inline std::shared_ptr<binSTnode<T>> BinSTree<T>::getNode(T src)
{
	if (!root || root->data == src)
		return root;
	else
	{
		std::shared_ptr<binSTnode<T>> res;
		return getNode(root, src, res);
	}
}




#endif