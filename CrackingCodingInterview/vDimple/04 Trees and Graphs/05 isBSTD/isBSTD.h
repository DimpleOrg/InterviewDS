#pragma once

#ifndef __ISBST_H_
#define __ISBST_H_

#include<iostream>

template<typename T>
struct BSTnode
{
	T data;
	std::shared_ptr<BSTnode<T>> left;
	std::shared_ptr<BSTnode<T>> right;
};

template<typename T>
class BST
{
	std::shared_ptr<BSTnode<T>> root;
	bool isBSTHelper(std::shared_ptr<BSTnode<T>> root, T max, T min);
	void insertNodeHelper(std::shared_ptr<BSTnode<T>> root, T val);
public:
	bool isBST();
	void insertNode(T val);
	BST(T val): root->data(val) { }
};


#endif


template<typename T>
inline void BST<T>::insertNode(T val)
{
	if (!root)
		root = std::make_shared<BSTnode<T>>(val);
	else
		insertNodeHelper(root, val);
}

template<typename T>
inline void BST<T>::insertNodeHelper(std::shared_ptr<BSTnode<T>> root, T val)
{
	if (root > data == val)
		throw("duplicate value");
	if (val < root->data)
	{
		if (root->left == nullptr)
			root->left = std::make_shared<BSTnode<T>>(val);
		else
			insertNodeHelper(root->left, val);
	}
	else
	{
		if (root->right == nullptr)
			root->right = std::make_shared<BSTnode<T>>(val);
		else
			insertNodeHelper(root->right, val);
	}
}

template<typename T>
inline bool BST<T>::isBSTHelper(std::shared_ptr<BSTnode<T>> root, T max, T min)
{
	if (!root) return true;
	if ((root->data > max) || (root->data < min))
		return false;
	return (isBSTHelper(root->left, root->data - 1, min) &&
			isBSTHelper(root->right, max, root->data + 1));
}

template<typename T>
inline bool BST<T>::isBST()
{
	return isBSTHelper(root, INT_MAX, INT_MIN);
}




