#pragma once
#include<iostream>
#include<queue>

template<typename T>
struct treeNode_01
{
	T data;
	std::shared_ptr<treeNode_01<T>> left;
	std::shared_ptr<treeNode_01<T>> right;
};

template<typename T>
class BTree_01
{
private:
	std::shared_ptr<treeNode_01<T>> getNode(std::shared_ptr<treeNode_01<T>> root, T src, std::shared_ptr<treeNode_01<T>>& res);
	void insertNodeHelper( T val);
	bool hasRoot2(std::shared_ptr<treeNode_01<T>> r1, std::shared_ptr<treeNode_01<T>> r2);
	bool isIdentical(std::shared_ptr<treeNode_01<T>> r1, std::shared_ptr<treeNode_01<T>> r2);
	std::queue<std::shared_ptr<treeNode_01<T>>> q;

public:
	std::shared_ptr<treeNode_01<T>> root;
	void insertNode(T val);
	std::shared_ptr<treeNode_01<T>> getNode(T src);
	bool chkSubTree(std::shared_ptr<treeNode_01<T>> r1, std::shared_ptr<treeNode_01<T>> r2);
};

template<typename T>
inline void BTree_01<T>::insertNode(T val)
{
	if (!root)
	{
		root = make_shared<treeNode_01<T>>();
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
		q.push(root);
	}
	else
		insertNodeHelper(val);
}

template<typename T>
inline void BTree_01<T>::insertNodeHelper(T val)
{
	auto node = q.front();
	if (node->left == nullptr)
	{
		node->left = make_shared<treeNode_01<T>>();
		node->left->data = val;
		q.push(node->left);
	}

	else if(node->right == nullptr)
	{
		node->right = make_shared<treeNode_01<T>>();
		node->right->data = val;
		q.pop();
		q.push(node->right);
	}
}

template<typename T>
inline std::shared_ptr<treeNode_01<T>> BTree_01<T>::getNode(std::shared_ptr<treeNode_01<T>> root, T src, std::shared_ptr<treeNode_01<T>>& res)
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
inline std::shared_ptr<treeNode_01<T>> BTree_01<T>::getNode(T src)
{
	if (!root || root->data == src)
		return root;
	else
	{
		std::shared_ptr<treeNode_01<T>> res;
		return getNode(root, src, res);
	}
}


template<typename T>
inline bool BTree_01<T>::chkSubTree(std::shared_ptr<treeNode_01<T>> r1, std::shared_ptr<treeNode_01<T>> r2)
{
	if (!r2)
		return true;	//empty tree is always a subtree
	return hasRoot2(r1, r2);
}

template<typename T>
inline bool BTree_01<T>::hasRoot2(std::shared_ptr<treeNode_01<T>> r1, std::shared_ptr<treeNode_01<T>> r2)
{
	bool res = false;
	if (!r1)
		return false;

	if (r1->data == r2->data)
		res = isIdentical(r1, r2);
	
	if (res)
		return true;
	else
	{
		hasRoot2(r1->left, r2);
		hasRoot2(r1->right, r2);
	}
	
	return res;
}

template<typename T>
inline bool BTree_01<T>::isIdentical(std::shared_ptr<treeNode_01<T>> r1, std::shared_ptr<treeNode_01<T>> r2)
{
	if (!r1 && !r2)
		return true;
	else
		if(!r1 || !r2)
			return false;

	if (r1->data == r2->data)
		return(isIdentical(r1->left, r2->left) &&
			isIdentical(r1->right, r2->right));
	else
		return false;
}
