#pragma once
#ifndef __LISTOFDEPTH_H_
#define __LISTOFDEPTH_H_

#include<iostream>
#include<vector>
#include<list>

using namespace std;

template <typename T>
struct node
{
	T data;
	shared_ptr<node<T>> left;
	shared_ptr<node<T>> right;
	explicit node(T val): data(val) { }
	
};

template<typename T>
class bTree
{
public:
	bTree() { }
	void insertNode(T val);
	vector<list<T>> listOfNodes();
	void listOfNodesHelper(shared_ptr<node<T>> root, vector<list<T>>& res, int level);

private:
	shared_ptr<node<T>> root;
	void insertNodeHelper(shared_ptr<node<T>> root, T val);
};

template<typename T>
inline void bTree<T>::insertNode(T val)
{
	if (!root)
	{
		root = make_shared<node<T>>(val);
		/*root->data = val;
		root->left = nullptr;
		root->right = nullptr;*/
	}
	else
		insertNodeHelper(root, val);
}

template<typename T>
inline void bTree<T>::insertNodeHelper(shared_ptr<node<T>> root, T val)
{
	if (root->data == val)
		throw("duplicate value");

	if (val < root->data)
	{
		if (root->left == nullptr)
		{
			root->left = make_shared<node<T>>(val);
			//root->left->data = val;
		}
		else
			insertNodeHelper(root->left, val);
	}

	if (val > root->data)
	{
		if (root->right == nullptr)
		{
			root->right = make_shared<node<T>>(val);
			//root->right->data = val;
		}
		else
			insertNodeHelper(root->right, val);
	}
}


template<typename T>
inline vector<list<T>> bTree<T>::listOfNodes()
{
	vector<list<T>> res;
	int level = 0;
	listOfNodesHelper(root, res, level);

	return res;
}

template<typename T>
inline void bTree<T>::listOfNodesHelper(shared_ptr<node<T>> root, vector<list<T>>& res, int level)
{
	if (!root)
		return;

	if (level < res.size())
	{
		res[level].push_back({ root->data });
	}
	else
	{
		res.push_back({ root->data });
	}

	listOfNodesHelper(root->left, res, level + 1);
	listOfNodesHelper(root->right, res, level + 1);
}



#endif