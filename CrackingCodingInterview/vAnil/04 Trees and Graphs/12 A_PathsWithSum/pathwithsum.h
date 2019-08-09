#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
class Node12
{
public:
	std::shared_ptr<Node12<T>> left;
	std::shared_ptr<Node12<T>> right;
	T data;

	Node12(const T& in) :data(in) {}
};

template <typename T>
class BT12
{
public:
	void insert(const T &data)
	{
		if (!root)
		{
			root = std::make_shared<Node12<T>>(data);
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

	
	size_t pathWithSum(int givenSum)
	{
		size_t countPathWithSum = 0;
		populateRootToLeafPath();
		for (auto x : rootToLeafPaths)
		{
			countPathWithSum += calSubPathWithSum(x, givenSum);
		}

		return countPathWithSum;
	}

private:
	std::shared_ptr<Node12<T>> root;
	std::vector<std::vector<T>> rootToLeafPaths;
	
	size_t calSubPathWithSum(std::vector<T> &path, int sum)
	{
		// create an empty map 
		std::unordered_map<int, int> map;
		size_t result = 0;
		// Maintains sum of elements so far 
		int curr_sum = 0;

		for (size_t i = 0; i < path.size(); i++)
		{
			// add current element to curr_sum 
			curr_sum = curr_sum + path[i];

			// if curr_sum is equal to target sum 
			// we found a subarray starting from index 0 
			// and ending at index i 
			if (curr_sum == sum)
			{
				result++;
			}

			// If curr_sum - sum already exists in map 
			// we have found a subarray with target sum 
			if (map.find(curr_sum - sum) != map.end())
			{
				std::cout << "Sum found between indexes "
					<< map[curr_sum - sum] + 1
					<< " to " << i << std::endl;
				result++;
			}

			map[curr_sum] = i;
		}

		return result;
	}


	void populateRootToLeafPath()
	{
		dfs(root, {});
	}


	void print(std::shared_ptr<Node12<T>> root)
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

	void insert(std::shared_ptr<Node12<T>> root, const T &data)
	{
		if (data < root->data)
		{
			if (!root->left)
				root->left = std::make_shared<Node12<T>>(data);
			else
				insert(root->left, data);
		}
		else
		{
			if (!root->right)
				root->right = std::make_shared<Node12<T>>(data);
			else
				insert(root->right, data);
		}
	}



	void dfs(std::shared_ptr<Node12<T>> ptr, std::vector<T> path)
	{
		if (!ptr)
		{
			return;
		}
		else if (!ptr->left && !ptr->right)
		{
			path.push_back(ptr->data);
			rootToLeafPaths.push_back(path);
			path.pop_back();
		}
		else
		{
			if (ptr->left)
			{
				path.push_back(ptr->data);
				dfs(ptr->left, path);
				path.pop_back();
			}

			if (ptr->right)
			{
				path.push_back(ptr->data);
				dfs(ptr->right, path);
				path.pop_back();
			}
		}
	}
};

