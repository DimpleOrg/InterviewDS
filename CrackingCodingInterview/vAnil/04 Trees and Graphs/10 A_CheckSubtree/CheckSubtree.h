#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Node10
{
public:
	std::shared_ptr<Node10<T>> left;
	std::shared_ptr<Node10<T>> right;
	T data;

	Node10(const T& in) :data(in) {}
};

template <typename T>
class BT10
{
public:
	void insert(const T &data)
	{
		if (!root)
		{
			root = std::make_shared<Node10<T>>(data);
		}
		else
		{
			insert(root, data);
		}
	}

	void insert(const std::vector<T>& vec)
	{
		for (auto x : vec)
		{
			insert(x);
		}
	}

	bool IsSubtree(BT10<T> &t);

	void print()
	{
		std::cout << std::endl << "Nodes=>";
		return print(root);
	}

private:
	std::shared_ptr<Node10<T>> root;

	void print(std::shared_ptr<Node10<T>> root)
	{
		if (!root)
		{
			return;
		}
		else
		{
			print(root->left);

			std::cout << root->data << " ";

			print(root->right);
		}
	}

	void insert(std::shared_ptr<Node10<T>> root, const T &data)
	{
		if (data < root->data)
		{
			if (!root->left)
				root->left = std::make_shared<Node10<T>>(data);
			else
				insert(root->left, data);
		}
		else
		{
			if (!root->right)
				root->right = std::make_shared<Node10<T>>(data);
			else
				insert(root->right, data);
		}
	}

	bool IsIdentical(std::shared_ptr<Node10<T>> t1, std::shared_ptr<Node10<T>> t2);
	bool IsSubtree(std::shared_ptr<Node10<T>> t1, std::shared_ptr<Node10<T>> t2);

};

template<typename T>
inline bool BT10<T>::IsSubtree(BT10<T>& t)
{
	if (!t.root)
	{
		return true;
	}
	else if (!root)
	{
		return false;
	}
	else
	{
		return IsSubtree(root, t.root);
	}
}

template<typename T>
inline bool BT10<T>::IsIdentical(std::shared_ptr<Node10<T>> t1, std::shared_ptr<Node10<T>> t2)
{
	if (!t2)
	{
		return true;
	}
	else if (t1 && t2)
	{
		if (t1->data != t2->data)
			return false;
		else
			return IsIdentical(t1->left, t2->left) && IsIdentical(t1->right, t2->right);

	}
	else
		return false;
}

template<typename T>
inline bool BT10<T>::IsSubtree(std::shared_ptr<Node10<T>> t1, std::shared_ptr<Node10<T>> t2)
{
	if (!t2)
	{
		return true;
	}
	else if (t1 && t2)
	{
		if (t1->data == t2->data)
		{
			return IsIdentical(t1, t2);
		}
		else
		{
			return IsSubtree(t1->left, t2) || IsSubtree(t1->right, t2);
		}
	}
	else
	{
		return false;
	}
}
