#pragma once
#ifndef __BST_H_
#define __BST_H_
#include <iostream>

template<typename T>
struct BSTNode
{
	T data;
	std::shared_ptr<BSTNode<T>> left, right;
}; 


template <typename T>
class BST
{
private:
	std::shared_ptr<BSTNode<T>> root;

	void insert(std::shared_ptr<BSTNode<T>>& node, T val);
	bool search(std::shared_ptr<BSTNode<T>>& node, T key);
	void inorder(std::shared_ptr<BSTNode<T>>& node);
public:
	void insert(T val);
	bool search(T key);
	void inorder();
};

template<typename T>
inline void BST<T>::insert(T val)
{
	if (!root)
	{
		root = std::make_shared<BSTNode<T>>();
		root->data = val;
	}
	else
	{
		insert(root, val);
	}
}


template<typename T>
inline void BST<T>::insert(std::shared_ptr<BSTNode<T>>& node, T val)
{
	if (val == node->data)
	{
		throw "Duplicate key";
	}
	else if (val < node->data)
	{
		if (!node->left)
		{
			node->left = std::make_shared<BSTNode<T>>();
			node->left->data = val;
		}
		else
		{
			insert(node->left, val);
		}
	}
	else
	{
		if (!node->right)
		{
			node->right = std::make_shared<BSTNode<T>>();
			node->right->data = val;
		}
		else
		{
			insert(node->right, val);
		}
	}
}

template<typename T>
inline bool BST<T>::search(std::shared_ptr<BSTNode<T>>& node, T key)
{

	if (!node)
		return false;

	if (node->data == key)
	{
		return true;
	}
	else if (key < node->data)
	{
		 search(node->left, key);
	}
	else
	{
		 search(node->right, key);
	}
}

template<typename T>
inline void BST<T>::inorder(std::shared_ptr<BSTNode<T>>& node)
{
	if (!node)
		return;

	inorder(node->left);

	std::cout << "\t" << node->data;

	inorder(node->right);
}


template<typename T>
inline bool BST<T>::search(T key)
{
	return search(root, key);
}

template<typename T>
inline void BST<T>::inorder()
{
	inorder(root);
}

#endif // __BST_H_
