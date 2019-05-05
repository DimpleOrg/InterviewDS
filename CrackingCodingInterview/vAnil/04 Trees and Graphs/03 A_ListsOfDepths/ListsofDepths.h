#pragma once
#include <iostream>
#include <list>
#include <vector>

template <typename T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode<T> *left = nullptr;
	BinaryTreeNode<T> *right = nullptr;

	BinaryTreeNode(T input) : data(input) {}
};

template <typename T>
class BinaryTree
{
public:
	std::vector<std::list<BinaryTreeNode<T> *>> createLevelLinkedList();

//	auto createLevelLinkedList();

	auto createLevelLinkedListIterative();

	void insert(T data) {
		if (!root)
		{
			root = new BinaryTreeNode<T>(data);
		}
		else
		{
			auto iter = root;
			auto prev = iter;
			while (iter)
			{
				prev = iter;
				if (data < iter->data)
				{
					iter = iter->left;
				}
				else if (data > iter->data)
				{
					iter = iter->right;
				}
				else
				{
					return;
				}
			}

			if (data < prev->data)
				prev->left = new BinaryTreeNode<T>(data);
			else if (data > prev->data)
				prev->right = new BinaryTreeNode<T>(data);
		}
	}

	void insert(std::list<T> dList)
	{
		for (auto val : dList)
		{
			insert(val);
		}
	}

private:
	BinaryTreeNode<T> *root = nullptr;

	void createLevelLinkedList(std::vector<std::list<BinaryTreeNode<T>*>> &lists, BinaryTreeNode<T> *root, size_t level);
};

template<typename T>
inline std::vector < std::list<BinaryTreeNode<T>* >> BinaryTree<T>::createLevelLinkedList()
{
	std::vector<std::list<BinaryTreeNode<T>*>> lists;
	createLevelLinkedList(lists, root, 0);
	return std::move(lists);
}

template<typename T>
inline auto BinaryTree<T>::createLevelLinkedListIterative()
{
	std::vector<std::list<BinaryTreeNode<T>*>> lists;

	if (!root)
		return lists;

	size_t level = 1;
	lists.push_back({ root });

	while (lists.size() == level++)
	{
		auto lastList = lists.back();

		lists.push_back({});

		auto &newList = lists.back();

		for (auto val : lastList)
		{
			if (val->left)
				newList.push_back(val->left);

			if (val->right)
				newList.push_back(val->right);				
		}

		if (newList.size() == 0)
			lists.pop_back();
	}

	return std::move(lists);
}

template<typename T>
inline void BinaryTree<T>::createLevelLinkedList(std::vector<std::list<BinaryTreeNode<T>*>>& lists, BinaryTreeNode<T>* root, size_t level)
{
	if (!root)
		return;

	if (lists.size() < level + 1)
	{
		lists.push_back({root});
	}
	else
	{
		lists[level].push_back(root);
	}

	createLevelLinkedList(lists, root->left, level + 1);
	createLevelLinkedList(lists, root->right, level + 1);
}

