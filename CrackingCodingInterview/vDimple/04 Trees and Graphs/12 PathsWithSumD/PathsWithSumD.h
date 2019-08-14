#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>

template<typename T>
struct treeNode_03
{
	T data;
	std::shared_ptr<treeNode_03<T>> left;
	std::shared_ptr<treeNode_03<T>> right;
};

template<typename T>
class BTree_03
{
private:
	std::shared_ptr<treeNode_03<T>> root;
	std::queue<std::shared_ptr<treeNode_03<T>>> q;
	std::vector<int> vec;
	
	void insertNodeHelper(T val);
	void print(std::shared_ptr<treeNode_03<T>> root);
	void countPaths(std::shared_ptr<treeNode_03<T>> root, int sum, int& numberOfPaths);
	int foundSumInVector(int sum);

public:
	void insertNode(T val);
	void print();
	int countPaths(int sum)
	{
		int numberOfPaths = 0;
		countPaths(root, sum, numberOfPaths);
		return numberOfPaths;
	}
};

template<typename T>
inline void BTree_03<T>::insertNode(T val)
{
	if (!root)
	{
		root = make_shared<treeNode_03<T>>();
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
		q.push(root);
	}
	else
		insertNodeHelper(val);
}

template<typename T>
inline void BTree_03<T>::insertNodeHelper(T val)
{
	auto node = q.front();
	if (node->left == nullptr)
	{
		node->left = make_shared<treeNode_03<T>>();
		node->left->data = val;
		q.push(node->left);
	}

	else if (node->right == nullptr)
	{
		node->right = make_shared<treeNode_03<T>>();
		node->right->data = val;
		q.pop();
		q.push(node->right);
	}
}

template<typename T>
inline void BTree_03<T>::print()
{
	print(root);
}

template<typename T>
inline void BTree_03<T>::print(std::shared_ptr<treeNode_03<T>> root)
{
	if (!root)
		return;
	std::cout << "\t" << root->data;
	print(root->left);
	print(root->right);
}

template<typename T>
inline void BTree_03<T>::countPaths(std::shared_ptr<treeNode_03<T>> root, int sum, int & numberOfPaths)
{
	if (!root)
		return;

	if (!root->left && !root->right)
	{
		vec.push_back(root->data);

		if (vec.size() > 0)
		{
			int count = foundSumInVector(sum);
			numberOfPaths += count;
		}

		vec.pop_back();

		return;
	}

	vec.push_back(root->data);
	countPaths(root->left, sum, numberOfPaths);
	countPaths(root->right, sum, numberOfPaths);

	vec.pop_back();
}

template<typename T>
inline int BTree_03<T>::foundSumInVector(int sum)
{
	int count = 0;
	int curr_sum = vec[0];
	std::unordered_map<int, int> umap;
	umap[curr_sum] = 0;

	for (int i = 1; i < vec.size(); i++)
	{
		curr_sum += vec[i];
		umap[curr_sum] = i;
		if (curr_sum == sum)
			count++;
	}

	for (auto each : umap)
	{
		if (umap.find(each.first - sum) != umap.end())
			count++;
	}
	
	return count;

	/*OR*/
	/* REFER TO: https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/*/
}



