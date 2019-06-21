#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Node8
{
public:
	T data;
	std::shared_ptr<Node8<T>> left;
	std::shared_ptr<Node8<T>> right;
	std::shared_ptr<Node8<T>> parent;

	Node8(const T &data) : data(data) {}
};


template <typename T>
class BST8
{
public:
	auto FirstCommonAncestorV1(std::shared_ptr<Node8<T>> n1, std::shared_ptr<Node8<T>> n2)
	{
		return FirstCommonAncestorV1(root, n1, n2);
	}

	auto FirstCommonAncestorV2(std::shared_ptr<Node8<T>> n1, std::shared_ptr<Node8<T>> n2)
	{
		int c1 = 0;
		int c2 = 0;

		auto p1 = n1;
		while (p1)
		{
			c1++;
			p1 = p1->parent;
		}

		auto p2 = n2;
		while (p2)
		{
			c2++;
			p2 = p2->parent;
		}

		p1 = n1;
		p2 = n2;

		if (c1 > c2)
		{
			int diff = c1 - c2;
			while (diff--)
			{
				p1 = p1->parent;
			}
		}
		else if (c2 > c1)
		{
			int diff = c2 - c1;
			while (diff--)
			{
				p2 = p2->parent;
			}
		}

		while (p1 && p2)
		{
			if (p1 == p2)
				return p1; //nullptr
			else
			{
				p1 = p1->parent;
				p2 = p2->parent;
			}
		}

		return p1; //nullptr
	}

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
	std::shared_ptr<Node8<T>> root;

	void InsertNode(std::shared_ptr<Node8<T>> &ptr, const T &data) const;
	auto getNodePtr(const std::shared_ptr<Node8<T>> &ptr, const T &data) const;
	auto FirstCommonAncestorV1(std::shared_ptr<Node8<T>> root, std::shared_ptr<Node8<T>> n1, std::shared_ptr<Node8<T>> n2)
	{
		static bool flag = false;
		if (!root)
		{
			return root;
		}

		if (n1 == root || n2 == root)
		{
			return root;
		}

		auto left = FirstCommonAncestorV1(root->left, n1, n2);
		if (flag)
			return left;

		auto right = FirstCommonAncestorV1(root->right, n1, n2);
		if (flag)
			return right;

		if (left && right) {
			return root; flag = true;
		}	
		else if (!left && !root)
			return left; //nullptr
		else if (left)
			return left;
		else
			return right;
	}
};


template <typename T>
void BST8<T>::InsertNode(const T &data)
{
	if (!root)
	{
		root = std::make_shared<Node8<T>>(data);
	}
	else
	{
		InsertNode(root, data);
	}
}

template<typename T>
inline auto BST8<T>::getNodePtr(const T & data) const
{
	return getNodePtr(root, data);
}

template<typename T>
inline void BST8<T>::InsertNode(std::shared_ptr<Node8<T>>& ptr, const T & data) const
{
	if (data < ptr->data)
	{
		if (!ptr->left)
		{
			ptr->left = std::make_shared<Node8<T>>(data);
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
			ptr->right = std::make_shared<Node8<T>>(data);
			ptr->right->parent = ptr;
		}
		else
		{
			InsertNode(ptr->right, data);
		}
	}
}

template<typename T>
inline auto BST8<T>::getNodePtr(const std::shared_ptr<Node8<T>>& ptr, const T & data) const
{
	if (!ptr)
		return ptr;
	else
	{
		if (ptr->data == data)
			return ptr;
		else if (data < ptr->data)
			return getNodePtr(ptr->left, data);
		else if (data > ptr->data)
			return getNodePtr(ptr->right, data);
	}
}
