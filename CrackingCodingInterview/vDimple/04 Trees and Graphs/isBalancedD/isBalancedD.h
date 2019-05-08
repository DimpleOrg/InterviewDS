#pragma once
#include<iostream>
#include<queue>

template<typename T>
struct treeNode
{
	T data;
	std::shared_ptr<treeNode<T>> left;
	std::shared_ptr<treeNode<T>> right;
};

template<typename T>
class BTree
{
public:
	std::shared_ptr<treeNode<T>> root;
	void insertNode(T val);
	void insertNodeHelper(std::shared_ptr<treeNode<T>> root, T val);
	bool isBalanced();
	int hOTree(std::shared_ptr<treeNode<T>> root);
};

template<typename T>
inline void BTree<T>::insertNode(T val)
{
	if (!root)
	{
		root = make_shared<treeNode<T>>();
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
		insertNodeHelper(root, val);

	/*if (!root)
	{
		root = std::make_shared<treeNode<T>>();
		root - data = val;
		vacantNodes.push(root);
	}
	else
	{
		std::shared_ptr<treeNode<T>> tempNode = vacantNodes.front();
		if (tempNode->left == nullptr)
		{
			tempNode->left = make_shared<treeNode<T>>();
			tempNode->left->data = val;
			vacantNodes.push(tempNode->left);
		}
		else
		{
			tempNode->right = make_shared<treeNode<T>>();
			tempNode->right->data = val;
			vacantNodes.push(tempNode->right);
			vacantNodes.pop();
		}
	}*/
}

template<typename T>
inline void BTree<T>::insertNodeHelper(std::shared_ptr<treeNode<T>> root, T val)
{
	if (root->data == val)
		throw("duplicate value");

	if (val < root->data)
	{
		if (root->left == nullptr)
		{
			root->left = make_shared<treeNode<T>>();
			root->left->data = val;
		}
		else
			insertNodeHelper(root->left, val);
	}

	if (val > root->data)
	{
		if (root->right == nullptr)
		{
			root->right = make_shared<treeNode<T>>();
			root->right->data = val;
		}
		else
			insertNodeHelper(root->right, val);
	}
}

template<typename T>
bool  BTree<T>::isBalanced()
{
	if (!root) return true;

	int res = hOTree(root);
	if (res >= 0)
		return true;
	else
		return false;
}

template<typename T>
int  BTree<T>::hOTree(std::shared_ptr<treeNode<T>> root)
{
		if (!root) return -1;
		int lh = hOTree(root->left) + 1;
		if (lh == -2)
			return -2;
		
		int rh = hOTree(root->right) + 1;
		if (rh == -2)
			return -2;
		
		if (abs(lh - rh) > 1)
			return -2;
		else
			return (lh > rh ? lh : rh);	
}