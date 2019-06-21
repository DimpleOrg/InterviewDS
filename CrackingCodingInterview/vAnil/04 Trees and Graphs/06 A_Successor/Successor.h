#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Node6
{
public:
	T data;
	std::shared_ptr<Node6<T>> left;
	std::shared_ptr<Node6<T>> right;
	std::shared_ptr<Node6<T>> parent;

	Node6(const T &data): data(data){}
};


template <typename T>
class BST6
{
public:
	auto GetSuccessor(const std::shared_ptr<Node6<T>> &ptr) const;
	void InsertNode(const T &data);
	auto getNodePtr(const T &data) const;

	void insert(std::vector<T> dList)
	{
		for (auto val : dList)
		{
			InsertNode(val);
		}
	}

private:
	std::shared_ptr<Node6<T>> root;

	void InsertNode(std::shared_ptr<Node6<T>> &ptr, const T &data) const;
	auto getNodePtr(const std::shared_ptr<Node6<T>> &ptr, const T &data) const;
};

template<typename T>
inline auto BST6<T>::GetSuccessor(const std::shared_ptr<Node6<T>>& ptr) const
{
	if (!ptr)
		return ptr;

	if (ptr->right)
	{
		auto rightRoot = ptr->right;
		auto prev = rightRoot;

		while (rightRoot)
		{
			prev = rightRoot;
			rightRoot = rightRoot->left;
		}

		return prev;
	}
	else
	{
		auto parent = ptr->parent;
		auto iter = ptr;

		while (parent)
		{
			if (parent->right == iter)
			{
				iter = parent;
				parent = parent->parent;
			}
			else
				break;
		}

		return parent;
	}
}

template <typename T>
void BST6<T>::InsertNode(const T &data)
{
	if (!root)
	{
		root = std::make_shared<Node6<T>>(data);
	}
	else
	{
		InsertNode(root, data);
	}
}

template<typename T>
inline auto BST6<T>::getNodePtr(const T & data) const
{
	return getNodePtr(root, data);
}

template<typename T>
inline void BST6<T>::InsertNode(std::shared_ptr<Node6<T>>& ptr, const T & data) const
{
	if (data < ptr->data)
	{
		if (!ptr->left)
		{
			ptr->left = std::make_shared<Node6<T>>(data);
			ptr->left->parent = ptr;
		}
		else
		{
			InsertNode(ptr->left, data);
		}
	}
	else if (data > ptr->data)
	{
		if (!ptr->right)
		{
			ptr->right = std::make_shared<Node6<T>>(data);
			ptr->right->parent = ptr;
		}
		else
		{
			InsertNode(ptr->right, data);
		}
	}
}

template<typename T>
inline auto BST6<T>::getNodePtr(const std::shared_ptr<Node6<T>>& ptr, const T & data) const
{
	if (!ptr)
		return ptr;
	else
	{
		if (ptr->data == data)
			return ptr;
		else if (data < ptr->data)
			return getNodePtr(ptr->left, data);
		else if(data > ptr->data)
			return getNodePtr(ptr->right, data);
	}
}
