#pragma once
#ifndef __SUCCESSOR_H_
#define __SUCCESSOR_H_

#include<iostream>

template<typename T>
struct bstnode
{
	T data;
	std::shared_ptr<bstnode<T>> left;
	std::shared_ptr<bstnode<T>> right;
	std::shared_ptr<bstnode<T>> parent;
	bstnode(T val) : data(val) { }
};

template<typename T>
class BSTree
{
	std::shared_ptr<bstnode<T>> root;
	void insertNodeHelper(std::shared_ptr<bstnode<T>> root, T val);
	std::shared_ptr<bstnode<T>> getSuccessorV1Helper(std::shared_ptr<bstnode<T>> root, T src, bool& flag);
	
	//--------------------- V2 -----------------------------

	bool isLeftChild(std::shared_ptr<bstnode<T>> src);
	bool isRightChild(std::shared_ptr<bstnode<T>> src);
	bool isRoot(std::shared_ptr<bstnode<T>> src);
	bool hasRightChild(std::shared_ptr<bstnode<T>> src);
	std::shared_ptr<bstnode<T>> leftMost(std::shared_ptr<bstnode<T>> src);
	std::shared_ptr<bstnode<T>> greaterParent(std::shared_ptr<bstnode<T>> src);
	std::shared_ptr<bstnode<T>> getNode(std::shared_ptr<bstnode<T>> root, T src, std::shared_ptr<bstnode<T>>& res);

public:
	
	void insertNode(T val);
	std::shared_ptr<bstnode<T>> getSuccessorV1(T src);
	std::shared_ptr<bstnode<T>> getSuccessorV2(std::shared_ptr<bstnode<T>> src);
	std::shared_ptr<bstnode<T>> getNode(T src);
	
};

template<typename T>
inline void BSTree<T>::insertNode(T val)
{
	if (!root)
		root = std::make_shared<bstnode<T>>(val);
	else
		insertNodeHelper(root, val);
}


template<typename T>
inline void BSTree<T>::insertNodeHelper(std::shared_ptr<bstnode<T>> root, T val)
{
	if (root->data == val)
		throw("duplicate value");

	if (val < root->data)
	{
		if (root->left == nullptr)
		{
			root->left = std::make_shared<bstnode<T>>(val);
			root->left->parent = root;
		}
		else
			insertNodeHelper(root->left, val);
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = std::make_shared<bstnode<T>>(val);
			root->right->parent = root;
		}
		else
			insertNodeHelper(root->right, val);
	}
}

template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::getSuccessorV1(T src)
{
	if ((!root) || ((root->data == src) && (!root->right)))
		return nullptr;
	bool flag = false;

	return getSuccessorV1Helper(root, src, flag);
}

template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::getSuccessorV1Helper(std::shared_ptr<bstnode<T>> root, T src, bool& flag)
{
	if (!root)
		return nullptr;

	auto val = getSuccessorV1Helper(root->left, src, flag);
	if (val)
		return val;

	if (flag)
	{
		if (root->data > src)
			return root;
	}
	if (root->data == src)
		flag = true;

	auto val1 = getSuccessorV1Helper(root->right, src, flag);
	if (val1)
		return val1;

	return nullptr;
}

//================================ V2 ======================================

template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::getSuccessorV2(std::shared_ptr<bstnode<T>> src)
{
	if (isRoot(src))
	{
		if (hasRightChild(src))
			return leftMost(src->right);
		else
			return nullptr;
	}

	if (isLeftChild(src))
		return src->parent;

	if (isRightChild(src))
	{
		if (hasRightChild(src))
			return leftMost(src->right);
		else
			return greaterParent(src);
	}
}

template<typename T>
inline bool BSTree<T>::isLeftChild(std::shared_ptr<bstnode<T>> src)
{
	return (src->parent->left == src);
}

template<typename T>
inline bool BSTree<T>::isRightChild(std::shared_ptr<bstnode<T>> src)
{
	return (src->parent->right == src);
}

template<typename T>
inline bool BSTree<T>::isRoot(std::shared_ptr<bstnode<T>> src)
{
	return (src->parent == nullptr);
}

template<typename T>
inline bool BSTree<T>::hasRightChild(std::shared_ptr<bstnode<T>> src)
{
	return (src->right != nullptr);
}

template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::leftMost(std::shared_ptr<bstnode<T>> src)
{
	while (src->left)
		src = src->left;

	return src;
}


template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::greaterParent(std::shared_ptr<bstnode<T>> src)
{
	std::shared_ptr<bstnode<T>> temp = src->parent;
	while (temp)
	{
		if (src->data < temp->data)
			return temp;
		else
			temp = temp->parent;
	}

	return temp;
}

template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::getNode(T src)
{
	if (!root || root->data == src)
		return root;
	else
	{
		std::shared_ptr<bstnode<T>> res;
		return getNode(root, src, res);
	}
}

template<typename T>
inline std::shared_ptr<bstnode<T>> BSTree<T>::getNode(std::shared_ptr<bstnode<T>> root, T src, std::shared_ptr<bstnode<T>>& res)
{
	if (!root) return nullptr;
	
	/*getNode(root->left, src, res);
	if (root->data == src)
		res= root;
	getNode(root->right, src, res);
	return res;*/

	auto val1 = getNode(root->left, src, res);
	if (val1) return val1;

	if (root->data == src)
		res= root;
	
	auto val2 = getNode(root->right, src, res);
	if (val2) return val2;

	return res;
}

#endif