#pragma once
#ifndef __FIRSTCOMMONANCESTOR_H_
#define __FIRSTCOMMONANCESTOR_H_

#include<iostream>

template<typename T>
struct bsrchtnode
{
	T data;
	std::shared_ptr<bsrchtnode<T>> left;
	std::shared_ptr<bsrchtnode<T>> right;
	std::shared_ptr<bsrchtnode<T>> parent;
	bsrchtnode(T val) : data(val) { }
};

template<typename T>
class BSrchTree
{
	std::shared_ptr<bsrchtnode<T>> root;
	void insertNodeHelper(std::shared_ptr<bsrchtnode<T>> root, T val);
	std::shared_ptr<bsrchtnode<T>> getNode(std::shared_ptr<bsrchtnode<T>> root, T src, std::shared_ptr<bsrchtnode<T>>& res);

public:
	void insertNode(T val);
	std::shared_ptr<bsrchtnode<T>> getNode(T src);
	std::shared_ptr<bsrchtnode<T>> getCommonAncestorV1(std::shared_ptr<bsrchtnode<T>> n1, std::shared_ptr<bsrchtnode<T>> n2);
	std::shared_ptr<bsrchtnode<T>> getCommonAncestorV2(std::shared_ptr<bsrchtnode<T>> root, std::shared_ptr<bsrchtnode<T>> n1, std::shared_ptr<bsrchtnode<T>> n2);
};

template<typename T>
inline void BSrchTree<T>::insertNode(T val)
{
	if (!root)
		root = std::make_shared<bsrchtnode<T>>(val);
	else
		insertNodeHelper(root, val);
}


template<typename T>
inline void BSrchTree<T>::insertNodeHelper(std::shared_ptr<bsrchtnode<T>> root, T val)
{
	if (root->data == val)
		throw("duplicate value");

	if (val < root->data)
	{
		if (root->left == nullptr)
		{
			root->left = std::make_shared<bsrchtnode<T>>(val);
			root->left->parent = root;
		}
		else
			insertNodeHelper(root->left, val);
	}
	else
	{
		if (root->right == nullptr)
		{
			root->right = std::make_shared<bsrchtnode<T>>(val);
			root->right->parent = root;
		}
		else
			insertNodeHelper(root->right, val);
	}
}


template<typename T>
inline std::shared_ptr<bsrchtnode<T>> BSrchTree<T>::getNode(T src)
{
	if (!root || root->data == src)
		return root;
	else
	{
		std::shared_ptr<bsrchtnode<T>> res;
		return getNode(root, src, res);
	}
}

template<typename T>
inline std::shared_ptr<bsrchtnode<T>> BSrchTree<T>::getCommonAncestorV1(std::shared_ptr<bsrchtnode<T>> n1, std::shared_ptr<bsrchtnode<T>> n2)
{
	if (!n1 || !n2)
		return nullptr;

	int count1 = 0;
	int count2 = 0;

	std::shared_ptr<bsrchtnode<T>> temp = n1->parent;
	while (temp)
	{
		count1++;
		temp = temp->parent;
	}

	temp = n2->parent;
	while (temp)
	{
		count2++;
		temp = temp->parent;
	}

	if (count1 > count2)
	{
		int diff = count1 - count2;
		while (diff--)
			n1 = n1->parent;
	}
	if (count2 > count1)
	{
		int diff = count2 - count1;
		while (diff--)
			n2 = n2->parent;
	}

	while (n1 != n2)
	{
		n1 = n1->parent;
		n2 = n2->parent;
	}

	return n1;		// can return any of n1 or n2
}

template<typename T>
inline std::shared_ptr<bsrchtnode<T>> BSrchTree<T>::getCommonAncestorV2(std::shared_ptr<bsrchtnode<T>> root, std::shared_ptr<bsrchtnode<T>> n1, std::shared_ptr<bsrchtnode<T>> n2)
{
	static bool flag = false;

	if (!root)
		return nullptr;

	if (root == n1 || root == n2)
		return root;

	std::shared_ptr<bsrchtnode<T>> left = getCommonAncestorV2(root->left, n1, n2);
	if (flag)
		return left;
	std::shared_ptr<bsrchtnode<T>> right = getCommonAncestorV2(root->right, n1, n2);
	if (flag)
		return right;

	if (left && right)
	{
		flag = true;
		return root;
	}
	else if (!left && !right)
		return nullptr;
	else if (left)
		return left;
	else
		return right;

}

template<typename T>
inline std::shared_ptr<bsrchtnode<T>> BSrchTree<T>::getNode(std::shared_ptr<bsrchtnode<T>> root, T src, std::shared_ptr<bsrchtnode<T>>& res)
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

#endif