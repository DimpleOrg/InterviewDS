#pragma once


#pragma once
#include <iostream>
#include <list>
#include <vector>

template <typename T>
class BinaryTreeNode5
{
public:
	T data;
	BinaryTreeNode5<T> *left = nullptr;
	BinaryTreeNode5<T> *right = nullptr;

	BinaryTreeNode5(T input) : data(input) {}
};

template <typename T>
class BinaryTree5
{
public:

	void insert(T data) {
		if (!root)
		{
			root = new BinaryTreeNode5<T>(data);
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
				prev->left = new BinaryTreeNode5<T>(data);
			else if (data > prev->data)
				prev->right = new BinaryTreeNode5<T>(data);
		}
	}

	void insert(std::list<T> dList)
	{
		for (auto val : dList)
		{
			insert(val);
		}
	}

	bool IsBSTv1() {
		if (!root)
			return true;
		else
		{
			T minimumData = getMin(root) ;
			minimumData--;
			return IsBSTv1(root, minimumData);
		}
	}

	bool IsBSTv2() {
		if (!root)
			return true;
		else
		{
			T minData = getMin(root);
			T maxData = getMax(root);

			return IsBSTv2(root, minData-1, maxData+1);
		}
	}

private:
	BinaryTreeNode5<T> *root = nullptr;

	bool IsBSTv1(BinaryTreeNode5<T> *root, T &data);
	bool IsBSTv2(BinaryTreeNode5<T> *root, T min, T max);
    
	//root should not be null
	T getMin(BinaryTreeNode5<T> *root)
	{
		while (root->left) {
			root = root->left;
		}

		return root->data;
	}

	//root should not be null
	T getMax(BinaryTreeNode5<T> *root)
	{
		while (root->right) {
			root = root->right;
		}

		return root->data;
	}
};

template <typename T>
bool BinaryTree5<T>::IsBSTv1(BinaryTreeNode5<T> *root, T &data)
{
	if (!root)
		return true;

	bool val = IsBSTv1(root->left, data);
	if (!val)
		return val;

	if (root->data <= data)
		return false;
	else//data is kind of global variable for this function becuase it modified value
		//could be accessed by each recursive call, it is used to store prev value
		data = root->data;

	bool val1 = IsBSTv1(root->right, data);

	if (!val1)
		return val1;

}

template <typename T>
bool BinaryTree5<T>::IsBSTv2(BinaryTreeNode5<T> *root, T min, T max)
{
	if (!root)
		return true;

	if ((root->left && root->data < root->left->data)
		|| (root->right && root->data > root->right->data)
		|| (root->data < min)
		|| (root->data > max))
	{
		return false;
	}
	else
	{
		return IsBSTv2(root->left, min, root->data) && IsBSTv2(root->right, root->data, max);
	}
}

