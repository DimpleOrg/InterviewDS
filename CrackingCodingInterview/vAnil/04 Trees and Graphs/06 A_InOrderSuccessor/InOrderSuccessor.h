#pragma once
#include <iostream>
#include <vector>

template <typename T>
class TreeNode
{
public:
	T data;
	std::shared_ptr<TreeNode> parent;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;

	TreeNode() {
		std::cout << "\n Created: " << data;
	}

	TreeNode(T input) :data(input) {}

	~TreeNode() {
		std::cout << "\n Destroyed: " << data;
	}

};

template <typename T>
class SuccTree
{
public:
	void insertNode(T input)
	{
		if (!root) {
			root = std::make_shared<TreeNode>(input);
		}
		else
		{
			auto prev;
			auto iter = root;

			while (iter)
			{
				prev = iter;

				if (iter->data > input)
				{
					iter = iter->left;
				}
				else if (iter->data < input)
				{
					iter = iter->right;
				}
				else
					return;
			}

			if (input < prev->data)
			{
				prev->left = std::make_shared<TreeNode>(input);
				prev->left->parent = prev;
			}
			else
			{
				prev->right = std::make_shared<TreeNode>(input);
				prev->right->parent = prev;
			}
		}
	}

	void insertListOfNodes(std::vector<T> nodeList)
	{
		for (auto var : nodeList)
		{
			insertNode(var);
		}
	}



private:
	std::shared_ptr<TreeNode> root;
};
