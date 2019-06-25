#pragma once
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>

template<typename T>
struct treeNode_02
{
	T data;
	std::shared_ptr<treeNode_02<T>> left;
	std::shared_ptr<treeNode_02<T>> right;
};

template<typename T>
class BTree_02
{
private:
	std::shared_ptr<treeNode_02<T>> root;
	std::queue<std::shared_ptr<treeNode_02<T>>> q;
	std::unordered_map<std::shared_ptr<treeNode_02<T>>, int> umap;
	std::vector<std::shared_ptr<treeNode_02<T>>> vec;

	std::shared_ptr<treeNode_02<T>> getNode(std::shared_ptr<treeNode_02<T>> root, T src, std::shared_ptr<treeNode_02<T>>& res);
	void insertNodeHelper(T val, std::queue<std::shared_ptr<treeNode_02<T>>> q);
	void deleteNode(std::shared_ptr<treeNode_02<T>> root, std::shared_ptr<treeNode_02<T>> node);
	void print(std::shared_ptr<treeNode_02<T>> root);

public:
	void insertNode(T val);
	std::shared_ptr<treeNode_02<T>> getNode(T src);
	void print();

	void deleteNode(T val)
	{
		auto node = getNode(val);
		deleteNode(node);
	}
	
	std::shared_ptr<treeNode_02<T>> getRandomNode();
};

template<typename T>
inline void BTree_02<T>::insertNode(T val)
{
	if (!root)
	{
		root = make_shared<treeNode_02<T>>();
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
		q.push(root);
		vec.push_back(root);
		umap.insert({ root,vec.size() - 1 });
	}
	else
		insertNodeHelper(root, val);
}

template<typename T>
inline void BTree_02<T>::insertNodeHelper(T val, std::queue<std::shared_ptr<treeNode_02<T>>> q)
{
	auto node = q.front();
	if (node->left == nullptr)
	{
		node->left = make_shared<treeNode_02<T>>();
		node->left->data = val;
		q.push(node->left);
		vec.push_back(node->left);
		umap.insert({ node->left,vec.size() - 1 });
	}

	else if (node->right == nullptr)
	{
		node->right = make_shared<treeNode_02<T>>();
		node->right->data = val;
		q.pop();
		q.push(node->right);
		vec.push_back(node->right);
		umap.insert({ node->right,vec.size() - 1 });
	}
}

template<typename T>
inline void BTree_02<T>::deleteNode(std::shared_ptr<treeNode_02<T>> root, std::shared_ptr<treeNode_02<T>> node)
{
	if (!root)
		return;

	if (root == node)
	{
		auto lastNode = q.back();
		root->data == lastNode->data;
		lastNode = nullptr;
		umap.erase(root->data);
	}
	else
	{
		deleteNode(root->left, node);
		deleteNode(root->right, node);
	}
}

template<typename T>
inline std::shared_ptr<treeNode_02<T>> BTree_02<T>::getNode(std::shared_ptr<treeNode_02<T>> root, T src, std::shared_ptr<treeNode_02<T>>& res)
{
	if (!root) return nullptr;

	auto val1 = getNode(root->left, src, res);
	if (val1) return val1;

	if (root->data == src)
		res = root;

	auto val2 = getNode(root->right, src, res);
	if (val2) return val2;

	return res;
}

template<typename T>
inline std::shared_ptr<treeNode_02<T>> BTree_02<T>::getNode(T src)
{
	if (!root || root->data == src)
		return root;
	else
	{
		std::shared_ptr<treeNode_02<T>> res;
		return getNode(root, src, res);
	}
}

template<typename T>
inline void BTree_02<T>::print()
{
	print(root);
}

template<typename T>
inline void BTree_02<T>::print(std::shared_ptr<treeNode_02<T>> root)
{
	if (!root)
		return;
	std::cout << "\t" << root->data;
	print(root->left);
	print(root->right);

}

