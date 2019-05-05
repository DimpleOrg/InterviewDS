#pragma once
#include <iostream>
#include <list>
#include <vector>

template <typename T>
class ABinaryTreeNode
{
public:
	T data;
	ABinaryTreeNode<T> *left = nullptr;
	ABinaryTreeNode<T> *right = nullptr;

	ABinaryTreeNode(T input) : data(input) {}
};

template <typename T>
class BinaryTreeA
{
public:
	
	void insert(T data) {
		if (!root)
		{
			root = new ABinaryTreeNode<T>(data);
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
				prev->left = new ABinaryTreeNode<T>(data);
			else if (data > prev->data)
				prev->right = new ABinaryTreeNode<T>(data);
		}
	}

	void insert(std::list<T> dList)
	{
		for (auto val : dList)
		{
			insert(val);
		}
	}

	bool IsBinaryTreeBalanced()
	{
		return IsBinaryTreeBalanced(root) != -2;
	}

private:
	ABinaryTreeNode<T> *root = nullptr;

	int IsBinaryTreeBalanced(ABinaryTreeNode<T> *root);

};

template<typename T>
inline int BinaryTreeA<T>::IsBinaryTreeBalanced(ABinaryTreeNode<T>* root)
{
	if (!root)
		return 0;

	int lh = IsBinaryTreeBalanced(root->left);
	if (lh == -2)
		return -2;

	int rh = IsBinaryTreeBalanced(root->right);
	if (rh == -2)
		return -2;

	if (abs(lh - rh) > 1)
		return -2;

	return (lh > rh ? lh : rh) + 1;
}
