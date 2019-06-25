#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

template <typename T>
class Node11
{
public:
	std::shared_ptr<Node11<T>> left;
	std::shared_ptr<Node11<T>> right;
	T data;

	Node11(const T& in) :data(in) {}
};

template <typename T>
class BT11
{
public:
	void insert(const T &data)
	{
		if (!root)
		{
			root = std::make_shared<Node11<T>>(data);
			addRandomNode(root);
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

	void print()
	{
		std::cout << std::endl << "Nodes=>";
		return print(root);
	}

	auto getRandomNode()
	{
		size_t len = nodeVec.size();

		size_t index = (rand() % len) + 1;

		return nodeVec[index - 1];
	}

	void deleteNode(T data)
	{
		if (!root) return;

		return deleteNode(root, data);
	}

private:
	std::shared_ptr<Node11<T>> root;
	
	std::unordered_map <std::shared_ptr<Node11<T>>,size_t> nodeSet;
	std::vector<std::shared_ptr<Node11<T>>> nodeVec;

	void addRandomNode(std::shared_ptr<Node11<T>>& ptr)
	{
		nodeVec.push_back(ptr);
		size_t index = nodeVec.size() - 1;

		nodeSet[ptr] = index;
	}

	void removeRandomNode(std::shared_ptr<Node11<T>>& ptr)
	{
		size_t rem = nodeSet[ptr];

		nodeSet.erase(ptr);
		nodeVec[rem] = nodeVec[nodeVec.size() - 1];
		nodeSet[nodeVec[rem]] = rem;

		nodeVec.pop_back();
	}

	void print(std::shared_ptr<Node11<T>> root)
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

	void insert(std::shared_ptr<Node11<T>> root, const T &data)
	{
		if (data < root->data)
		{
			if (!root->left) {
				root->left = std::make_shared<Node11<T>>(data);
				addRandomNode(root->left);
			}
			else
				insert(root->left, data);
		}
		else
		{
			if (!root->right) {
				root->right = std::make_shared<Node11<T>>(data);
				addRandomNode(root->right);
			}
			else
				insert(root->right, data);
		}
	}

	void deleteNode(std::shared_ptr<Node11<T>> ptr, T data)
	{
		if (!ptr || !root)
			return;

		if (ptr->data == data)
		{
			if (!root->right)
			{
				ptr->data = root->data;
				removeRandomNode(root);
				root = root->left;
			}
			else
			{
				auto iter = root;
				auto prev = iter;

				while (iter->right)
				{
					prev = iter;
					iter = iter->right;
				}

				ptr->data = iter->data;
				removeRandomNode(prev->right);
				prev->right = nullptr;
			}

			return;
		}
		else
		{
			deleteNode(ptr->left, data);
			deleteNode(ptr->right, data);
		}
	}
};

